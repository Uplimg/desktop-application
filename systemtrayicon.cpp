#include "systemtrayicon.h"

SystemTrayIcon::SystemTrayIcon()
{
    QMenu *root = new QMenu;

    captureScreen = root->addAction("Capture screen");
    captureArea = root->addAction("Capture area");
    createPaste = root->addAction("Create paste");
    sendFile = root->addAction("Send file");
    root->addSeparator();
    open = root->addAction("Open");
    quit = root->addAction("Quit");
    root->addSeparator();
    root->addAction("Uplimg 1.0 Nightly")->setDisabled(true);

    connect(captureScreen, &QAction::triggered, &actions, &SystemTrayActions::captureScreen);
    connect(captureArea, &QAction::triggered, &actions, &SystemTrayActions::captureArea);
    connect(sendFile, &QAction::triggered, &actions, &SystemTrayActions::sendFile);
    connect(open, &QAction::triggered, &actions, &SystemTrayActions::openWindow);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    setContextMenu(root);
    setIcon(QIcon(":/resources/logo.ico"));
    root->setTearOffEnabled(true);

    // DEBUG ONLY
    actions.openWindow();
}
