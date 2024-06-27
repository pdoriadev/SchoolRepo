#include "AudioAssetContentEditor.hpp"
#include "Conductor/Editor/Overlay/SoundBank/SoundBankOverlay.hpp"
#include "../../../../../../EngineContribModules/soloud/include/soloud.h"
#include "../../../../../../EngineContribModules/soloud/include/soloud_wav.h"
//#include <sys/stat.h>
//#include <sys/types.h>
#include <filesystem>
#include <QStandardItemModel>


AudioAssetContentEditorView::AudioAssetContentEditorView(QWidget* parentWidget) : QFrame(parentWidget)
{
    m_DesignerUI = std::make_unique<Ui_AudioAssetContentEditorView>();
    m_DesignerUI->setupUi(this);

    QStringList ColumnLabels;
    ColumnLabels.append("Attribute");
    ColumnLabels.append("Value");

    //Setup some basic properties for the
    QStandardItemModel* standardModel = new QStandardItemModel(m_DesignerUI->AttributesTable);

    //Set Column Header information
    constexpr const size_t NumberOfColumns{1};
    constexpr const size_t NumberOfRows{10};
    standardModel->setColumnCount(NumberOfColumns);
    standardModel->setHeaderData(0, Qt::Orientation::Horizontal, "Value", Qt::EditRole);

    //Set Row Header Information
    standardModel->setRowCount(NumberOfRows);
    standardModel->setHeaderData(0, Qt::Orientation::Vertical, "Name", Qt::EditRole);
    standardModel->setHeaderData(1, Qt::Orientation::Vertical, "UUID", Qt::EditRole);
    standardModel->setHeaderData(2, Qt::Orientation::Vertical, "SoundBank", Qt::EditRole);
    standardModel->setHeaderData(3, Qt::Orientation::Vertical, "ContentHash", Qt::EditRole);
    standardModel->setHeaderData(4, Qt::Orientation::Vertical, "Channels", Qt::EditRole);
    standardModel->setHeaderData(5, Qt::Orientation::Vertical, "Format", Qt::EditRole);
    standardModel->setHeaderData(6, Qt::Orientation::Vertical, "Length", Qt::EditRole);
    standardModel->setHeaderData(7, Qt::Orientation::Vertical, "Filesize", Qt::EditRole);
    standardModel->setHeaderData(8, Qt::Orientation::Vertical, "Project Relative Filepath", Qt::EditRole);
    standardModel->setHeaderData(9, Qt::Orientation::Vertical, "Absolute Filepath", Qt::EditRole);

    QColor backgroundColor;
    backgroundColor.setRgb(150, 255, 150, 255);
    for(int currentColumn = 0; currentColumn < NumberOfColumns; currentColumn++)
    {
        for(int currentRow = 0; currentRow < NumberOfRows; currentRow++)
        {
            QStandardItem* item = new QStandardItem("HelloWorld");
            item->setData(Qt::AlignCenter, Qt::TextAlignmentRole);

            //Everyother row should be highlighted in green
            if(currentRow % 2)
                item->setData(QVariant(QBrush(backgroundColor)), Qt::BackgroundRole);

            standardModel->setItem(currentRow, currentColumn, item);
        }
    }

    m_DesignerUI->AttributesTable->setModel(standardModel);
    //m_DesignerUI->AttributesTable->setHorizontalHeaderLabels()
}

bool AudioAssetContentEditorView::SetAudioAsset(Conductor::SoundBank* targetSoundBank, Conductor::AudioAsset* audioAssetToEdit)
{
    if(audioAssetToEdit == nullptr)
        return false;

    if(!PopulateFields(targetSoundBank, audioAssetToEdit))
        return false;

    m_AudioAssetParentSoundbank = targetSoundBank;
    m_EditingAudioAsset = audioAssetToEdit;
    return true;
}

bool AudioAssetContentEditorView::PopulateFields(Conductor::SoundBank* targetSoundBank, Conductor::AudioAsset* targetAudioAsset)
{
    m_DesignerUI->NameContent->setText(targetAudioAsset->Name().c_str());
    m_DesignerUI->UUIDContent->setText(targetAudioAsset->UUID().str().c_str());

    Conductor::Editor::SoundBankOverlay targetSoundBankOverlay(targetSoundBank);
    m_DesignerUI->SoundBankContent->setText(targetSoundBankOverlay.GetName().c_str());
    m_DesignerUI->NameContent->setText(targetAudioAsset->Name().c_str());
    m_DesignerUI->UUIDContent->setText(targetAudioAsset->UUID().str().c_str());
    m_DesignerUI->HashContent->setText(targetAudioAsset->FileHash().c_str());
    m_DesignerUI->ChannelsContent->setText(std::to_string(targetAudioAsset->Channels()).c_str());

    // https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_stat.h.html
    // https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_types.h.html
    // https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-stat-stat64-get-file-information
//    struct stat * assetFileInfo;
//    stat(targetAudioAsset->Filepath().c_str(), assetFileInfo);
//    assert( S_ISLNK(assetFileInfo->st_mode) != 0 && "Not a symlink file. Is reg file.");
//    assert( S_ISREG(assetFileInfo->st_mode) != 0 && "Not a regular file. Is symbolic link. Will not be able to get size using stat.");

    std::filesystem::path audioAssetGivenPath = targetAudioAsset->Filepath().c_str();
    std::filesystem::path absolutePath = std::filesystem::absolute(audioAssetGivenPath);

    bool exists = std::filesystem::exists(absolutePath);
    bool isRegFile = std::filesystem::is_regular_file(absolutePath);
    bool isSymLink = std::filesystem::is_symlink(absolutePath);
    bool isBlockFile = std::filesystem::is_block_file(absolutePath);
    bool isCharacterFile = std::filesystem::is_character_file(absolutePath);
    bool isOther = std::filesystem::is_other(absolutePath);
    bool isEmpty = std::filesystem::is_empty(absolutePath);

    std::error_code * errorCode;
    std::uintmax_t size = std::filesystem::file_size(absolutePath);

//    size += assetFileInfo->st_size % 1000000000;
//    if (size > 0)
//    {
//        size += ((assetFileInfo->st_size - int(size)) % 1000000) * 0.001;
//        sizeText = std::to_string(size) + " GB";
//    }

//    if (size == 0)
//    {
//        size = assetFileInfo->st_size % 1000000;
//        if (size > 0)
//        {
//            size += ((assetFileInfo->st_size - int(size)) % 1000) * 0.001;
//        }

//        sizeText = std::to_string(size) + " MB";
//    }

//    if (size == 0)
//    {
//        size = assetFileInfo->st_size % 1000;
//        size += ((assetFileInfo->st_size - int(size)) % 1) * 0.001;
//        sizeText = std::to_string(size) + " KB";
//    }

//    m_DesignerUI->FilesizeLabel->setText(sizeText.c_str());



//    SoLoud::Soloud soLoudEng;
//    soLoudEng.init();

//    SoLoud::Wav wav;
//    SoLoud::SOLOUD_ERRORCODE err = wav.load(targetAudioAsset->Filepath().c_str());

//    double length = wav.getLength();
//    int minutes = static_cast<int>(length) / 60;
//    std::string lengthStr = std::to_string(minutes) + " min, " + std::to_string(length - minutes) + " sec";
//    m_DesignerUI->AudioLengthContent->setText(lengthStr.c_str());


//    //m_DesignerUI->FilesizeContent

//    soLoudEng.deinit();

    m_DesignerUI->ProjectRelativeFilepathContent->setText(targetAudioAsset->Filepath().c_str());
    //m_DesignerUI->AbsoluteFilepathContent
    return false;
}
