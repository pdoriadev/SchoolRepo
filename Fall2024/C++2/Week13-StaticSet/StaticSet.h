#ifndef STATICSET_H
#define STATICSET_H

#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>

template <typename T>
class StaticSet {
private:
    const std::unordered_set<T> set;

public:
    // Constructs an empty StaticSet
    StaticSet() {
    }

    // Constructs the StaticSet by adding all vector items
    StaticSet(const std::vector<T>& items) {
        for (const T& item : items) {
            set.emplace(item);
        }
    }

    // Constructs the StaticSet by copying itemsToCopy's items
    StaticSet(const std::unordered_set<T>& itemsToCopy) : set(itemsToCopy) {
    }

    virtual ~StaticSet() {
    }

    bool Contains(const T& item) const {
        return 1 == set.count(item);
    }

    int GetSize() const {
        return (int)set.size();
    }

    const std::unordered_set<T>& GetSet() const
    {
        return set;
    }

    void Print(std::ostream& output, std::string separator,
        std::string prefix = "", std::string suffix = "") const {
        output << prefix;
        bool firstItem = true;
        for (const T& item : set) {
            if (firstItem) {
                output << item;
                firstItem = false;
            }
            else {
                output << separator << item;
            }
        }
        output << suffix;
    }

    // Returns a StaticSet<T> containing every element from this set and every
// element from otherSet.
    StaticSet<T> Union(const StaticSet& otherSet) const {

        const std::unordered_set<T>& underlyingOther = otherSet.GetSet();
        std::unordered_set<T> newSet = set;
        for (auto it = underlyingOther.begin(); it != underlyingOther.end(); ++it)
        {
            newSet.emplace(*it);
        }

        return StaticSet<T>(newSet);
    }

    // Returns a StaticSet<T> containing each element from this set that is also
 // in otherSet.
    StaticSet<T> Intersection(const StaticSet& otherSet) const {

        std::unordered_set<T> newSet;
        for (auto it = set.begin(); it != set.end(); ++it)
        {
            if (otherSet.Contains(*it))
            {
                newSet.emplace(*it);
            }
        }

        return StaticSet<T>(newSet);
    }

    // Returns a StaticSet<T> containing each element from this set that is not
    // in otherSet.
    StaticSet<T> Difference(const StaticSet& otherSet) const {

        std::unordered_set<T> newSet;
        for (auto it = set.begin(); it != set.end(); ++it)
        {
            if (otherSet.Contains(*it) == false)
            {
                newSet.emplace(*it);
            }
        }

        return StaticSet<T>(newSet);
    }

    // Returns a StaticSet<T> containing each element from this set that
    // satisfies the predicate.
    // - If predicate(item) returns true, item satisfies the predicate.
    // - If predicate(item) returns false, item does not satisfy the predicate.
    StaticSet<T> Filter(std::function<bool(const T&)> predicate) const {

        std::unordered_set<T> newSet;
        for (auto it = set.begin(); it != set.end(); ++it)
        {
            if (predicate(*it))
            {
                newSet.emplace((*it));
            }
        }

        return StaticSet<T>(newSet);
    }

    // Calls mapFunction(item) for each item in this set and adds the returned
    // item to a StaticSet<U>. After mapFunction has been called for each item
    // in this set, the StaticSet<U> object is returned.
    template <typename U>
    StaticSet<U> Map(std::function<U(const T&)> mapFunction) const {

        std::unordered_set<U> newSet;
        for (auto it = set.begin(); it != set.end(); ++it)
        {
            newSet.emplace(mapFunction((*it)));
        }

        return StaticSet<U>(newSet);
    }


};

#endif