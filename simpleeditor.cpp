#include "simpleeditor.h"
#include "./ui_simpleeditor.h"

SimpleEditor::SimpleEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleEditor)
{
    ui->setupUi(this);
}

SimpleEditor::~SimpleEditor()
{
    delete ui;
}
