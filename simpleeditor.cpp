#include "simpleeditor.h"
#include "./ui_simpleeditor.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QPalette>
#include <QFileDialog>

SimpleEditor::SimpleEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleEditor)
{
    ui->setupUi(this);

    // Video player
    player = new VideoPlayer;
    ui->main_workspace->addWidget(player);

    // Connect menu button to functions
    connect(ui->actionOpenVideo, &QAction::triggered, this, &SimpleEditor::selectVideoFile);

    // Connect video player to file change action
    connect(this, &SimpleEditor::videoFileChanged, player, &VideoPlayer::setVideoFile);
}

SimpleEditor::~SimpleEditor()
{
    delete ui;
}

void SimpleEditor::selectVideoFile()
{
    // Create video select dialog
    QString fileName = QFileDialog::getOpenFileName(this, "Open Video", "/home", "Videos (*.mp4 *.mov *.avi)");

    // Update video
    emit videoFileChanged(fileName);
}
