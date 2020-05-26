#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "RabbitCommonDir.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pChess = new CFrmChineseChess(this);
    this->setCentralWidget(m_pChess);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_O_triggered()
{
    if(!m_pChess) return;
    QString szFile = RabbitCommon::CDir::GetOpenFileName(this,
                                                         tr("Open chess game"));
    m_pChess->LoadChessGame(szFile.toStdString().c_str());
}

void MainWindow::on_actionSave_S_triggered()
{
    if(!m_pChess) return;
    QString szFile = RabbitCommon::CDir::GetSaveFileName(this,
                                                         tr("Open chess game"));
    m_pChess->SaveChessGame(szFile.toStdString().c_str());
}

void MainWindow::on_actionPreviou_P_triggered()
{
    if(m_pChess)
        m_pChess->PreviouStep();
}

void MainWindow::on_actionNext_N_triggered()
{
    if(m_pChess)
        m_pChess->NextStep();
}

void MainWindow::on_actionExit_E_triggered()
{
    qApp->exit();
}