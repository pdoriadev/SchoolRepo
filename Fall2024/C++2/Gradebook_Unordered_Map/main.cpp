#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>
#include <iterator>


class Gradebook {
public:
    virtual ~Gradebook() {
    }

    // GetScore() returns the specified student's score for the specified
    // assignment. NAN is returned if either:
    // - the assignment does not exist in the gradebook, or
    // - the assignment exists but no score exists for the specified student.
    virtual double GetScore(std::string assignmentName, int studentID) = 0;

    // SetScore() adds or updates a score in the gradebook.
    virtual void SetScore(std::string assignmentName, int studentID,
        double score) = 0;

    // GetAssignmentScores() returns an unordered_map that maps a student ID to
    // the student's corresponding score for the specified assignment. An entry
    // exists in the returned map only if a score has been entered with the
    // SetScore() function.
    virtual std::unordered_map<int, double> GetAssignmentScores(
        std::string assignmentName) = 0;

    // GetSortedAssignmentNames() returns a vector with all distinct assignment
    // names, sorted in ascending order.
    virtual std::vector<std::string> GetSortedAssignmentNames() = 0;

    // GetSortedStudentIDs() returns a vector with all distinct student IDs,
    // sorted in ascending order.
    virtual std::vector<int> GetSortedStudentIDs() = 0;

    // GetStudentScores() gets all scores that exist in the gradebook for the 
    // student whose ID matches the function parameter. GetStudentScores() 
    // returns an unordered_map that maps an assignment name to the student's 
    // corresponding score for that assignment.
    virtual std::unordered_map<std::string, double> GetStudentScores(
        int studentID) = 0;
};

// https://stackoverflow.com/questions/8483985/obtaining-list-of-keys-and-values-from-unordered-map
// https://stackoverflow.com/questions/44251704/auto-error-map-iterator-has-no-member-named-first
// https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
// https://en.cppreference.com/w/cpp/container/unordered_map

class Entry {
public:
    int ID = -1;
    std::string assignmentName = "";
    int score = -1;

    Entry() {}

    Entry(int id, std::string name, int sco) {
        ID = id;
        assignmentName = name;
        score = sco;
    }
};

class CourseGradebook : public Gradebook {
protected:

    std::unordered_map<int, std::vector<int>> m_IDsTable;
    std::vector<int> m_IDs = {};

    std::unordered_map<std::string, std::vector<int>> m_AssignmentsTable;
    std::vector<std::string> m_Names;

    std::vector<Entry> m_Entries;

public:
    CourseGradebook() {
        m_Entries.reserve(100);
    }

    virtual ~CourseGradebook() {

    }

    // receive assignmentName --> get all scores for that assignment
    // constructs a new unordered_map<int, double>. Returns a copy of the object.
    std::unordered_map<int, double> GetAssignmentScores(
        std::string assignmentName) override {

        auto iterator = m_AssignmentsTable.find(assignmentName);
        // no matching assignment name in table. return empty map.
        if (iterator == m_AssignmentsTable.end()) {
            return std::unordered_map<int, double>();
        }

        std::unordered_map<int, double> idScoreMap{};
        // iterates through all the student's gradebook entries
        for (int entryIndex : m_AssignmentsTable.at(assignmentName)) {
            Entry entry = m_Entries[entryIndex];
            std::pair<int, double> newPair = std::make_pair(entry.ID, entry.score);
            idScoreMap.emplace(newPair);
        }

        return idScoreMap;
    }

    // receive assignmentName and ID --> get student's score for assignment
    double GetScore(std::string assignmentName, int studentID) override {

        if (0 == m_IDsTable.count(studentID)) {
            return -1;
        }

        double score = -1;
        for (int entryIndex : m_IDsTable.at(studentID)) {
            if (assignmentName == m_Entries[entryIndex].assignmentName) {
                score = m_Entries[entryIndex].score;
                break;
            }
        }

        return score;
    }


    std::vector<std::string> GetSortedAssignmentNames() override {

        std::vector<std::string> names = m_Names;
        std::sort(names.begin(), names.end());

        return names;
    }

    // GetSortedStudentIDs() returns a vector with all distinct student IDs,
    // sorted in ascending order.
    std::vector<int> GetSortedStudentIDs() override {

        std::vector<int> iDs = m_IDs;
        std::sort(iDs.begin(), iDs.end());

        return iDs;
    }

    // GetStudentScores() gets all scores that exist in the gradebook for the
    // student whose ID equals the studentID parameter. Scores are returned as
    // an unordered_map that maps an assignment name to the student's
    // corresponding score for that assignment.
    std::unordered_map<std::string, double> GetStudentScores(
        int studentID) override {

        auto iterator = m_IDsTable.find(studentID);
        if (iterator == m_IDsTable.end()) {
            return std::unordered_map<std::string, double>();
        }

        std::unordered_map<std::string, double> assignmentScoreMap{};
        // iterates through all the student's gradebook entries
        for (int entryIndex : m_IDsTable.at(studentID)) {
            Entry entry = m_Entries[entryIndex];
            std::pair<std::string, double> newPair = std::make_pair(entry.assignmentName, entry.score);
            assignmentScoreMap.emplace(newPair);
        }

        return assignmentScoreMap;
    }


    void SetScore(std::string assignmentName, int studentID, double score) override {
        // receives new entry into gradebook.
        // sorts assignment names.

        // ADD NEW GRADEBOOK ENTRY TO ENTRIES VECTOR
        m_Entries.emplace_back(Entry(studentID, assignmentName, score));

        // UPDATE ASSIGNMENTS MAP
        {
            auto iterator = m_AssignmentsTable.find(assignmentName);
            if (iterator != m_AssignmentsTable.end()) {
                m_AssignmentsTable.at(assignmentName).emplace_back(m_Entries.size() - 1);
            }
            else {
                m_AssignmentsTable.emplace(assignmentName, std::vector<int>());
                m_AssignmentsTable.at(assignmentName).emplace_back(m_Entries.size() - 1);
                m_Names.emplace_back(assignmentName);
            }
        }

        // UPDATE STUDENT IDs MAP
        {
            auto iterator = m_IDsTable.find(studentID);
            if (iterator != m_IDsTable.end()) {
                m_IDsTable.at(studentID).emplace_back(m_Entries.size() - 1);
            }
            else {
                m_IDsTable.emplace(studentID, std::vector<int>());
                m_IDsTable.at(studentID).emplace_back(m_Entries.size() - 1);
                m_IDs.emplace_back(studentID);
            }
        }
    }

};





int main()
{
    std::cout << "Hello World";
    CourseGradebook book;
    book.SetScore("hw1", 111, 90);
    std::cout << "Score: " << book.GetScore("hw1", 111) << '\n';


    return 0;
}

