#ifndef PROFILEIMPORTER_H
#define PROFILEIMPORTER_H

#include <QWidget>
#include <QButtonGroup>

#include <string>

class AntiMicroSettings;


namespace Ui
{
    class ProfileImporter;
}

namespace Converters
{

    const QHash<QString, int> joyToKeyForAntimicro {
        { "Axis1n", 11 }, // left (left-stick)
        { "Axis1p", 11 }, // right (left-stick)
        { "Axis2n", 12 }, // up (left-stick)
        { "Axis2p", 12 }, // down (left-stick)
        { "Axis3n", 13 }, // left (right-stick)
        { "Axis3p", 13 }, // right (right-stick)
        { "Axis4n", 14 }, // up (right-stick)
        { "Axis4p", 14 }, // down (right-stick)
    /*  { "Axis5n", },
        { "Axis5p", },
        { "Axis6n", },
        { "Axis6p", },
        { "Axis7n", },
        { "Axis7p", },
        { "Axis8n", },
        { "Axis8p", },
        { "Up-Right", },
        { "Up- Left", },
        { "Dn- Left", },
        { "Dn-Right", },
        { "Up-Right2", },
        { "Up- Left2", },
        { "Dn- Left2", },
        { "Dn-Right2", }, */
        { "POV1-1", 17 }, // arrow up
     // { "POV1-2", },
        { "POV1-3", 20 }, // arrow right
    //  { "POV1-4", },
        { "POV1-5", 19 }, // arrow down
    //  { "POV1-6", },
        { "POV1-7", 18 }, // arrow left
    /*  { "POV1-8", },
        { "POV2-1", },
        { "POV2-2", },
        { "POV2-3", },
        { "POV2-4", },
        { "POV2-5", },
        { "POV2-6", },
        { "POV2-7", },
        { "POV2-8", },
        { "POV3-1", },
        { "POV3-2", },
        { "POV3-3", },
        { "POV3-4", },
        { "POV3-5", },
        { "POV3-6", },
        { "POV3-7", },
        { "POV3-8", },
        { "POV4-1", },
        { "POV4-2", },
        { "POV4-3", },
        { "POV4-4", },
        { "POV4-5", },
        { "POV4-6", },
        { "POV4-7", },
        { "POV4-8", }, */
        { "Button01", 2 },
        { "Button02", 0 },
        { "Button03", 1 },
        { "Button04", 3 },
        { "Button05", 7 },
        { "Button06", 8 },
        { "Button07", 15 },
        { "Button08", 16 },
        { "Button09", 4 },
        { "Button10", 5 },
        { "Button11", 9 },
        { "Button12", 10 }
   /*   { "Button13", },
        { "Button14", },
        { "Button15", },
        { "Button16", },
        { "Button17", },
        { "Button18", },
        { "Button19", },
        { "Button20", },
        { "Button21", },
        { "Button22", },
        { "Button23", },
        { "Button24", },
        { "Button25", },
        { "Button26", },
        { "Button27", },
        { "Button28", },
        { "Button29", },
        { "Button30", },
        { "Button31", },
        { "Button32", } */
    };

    // temporarily blocked until it will appear an occasion for making tests
  /*  const QHash<QString, QString> xPadderForAntimicro {
        { , },
        { , },
        { , }
    };

    const QHash<QString, QString> pinnacleForAntimicro {
        { , },
        { , },
        { , }
    }; */
}


class ProfileImporter : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileImporter(AntiMicroSettings* settings, QWidget *parent = 0);
    ~ProfileImporter();

    void changeExtensionFile(QString filePath);
    void backExtensionFile(QString filePath);
    QString profilePath();
    void openFile(QString profilePath);
    void readSettGroups();
    int convertStringToQtKey(QString const & keyString);
    QChar convertHexToString_QChar(QString const & hexValue);
    char convertHexToString_char(std::string const & hexValue);


protected:
    bool allFilled();
    bool properExtension(QString profilePath);
    QString extensionProfile();


private slots:
    void on_AcceptBtn_clicked();
    void on_cancelBtn_clicked();
    void on_findProfileBtn_clicked();
    void on_fullSettCheckBox_stateChanged(int state);


private:
    Ui::ProfileImporter *ui;

    QHash<QString, QString> antToCurrGamepads;

    AntiMicroSettings *settings;
    QString chosenFile;
    QButtonGroup radioBtnProfiles;
    QString displayedModeJoyToKey;
    QString buttonMode;

    void putSettingsToApp();
    void putGamecontrMapping();
    QString displayModeJoyToKey();
    void rewriteButtonGroup();
    QString filedialogDescExt();

};

#endif // PROFILEIMPORTER_H
