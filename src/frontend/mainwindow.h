#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QStandardPaths>

#include "../QtGifImage/src/gifimage/qgifimage.h"
#include "widgetogl.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_selectFile_clicked();
  void on_perspective_stateChanged(int arg1);
  void on_edgeColorBtn_clicked();
  void on_edgeThickBox_valueChanged(int arg1);
  void on_edgeDashChk_stateChanged(int arg1);
  void on_vColorBtn_clicked();
  void on_vSizeBox_valueChanged(int arg1);
  void onDispMethodClicked();
  void on_bgColorBtn_clicked();
  void onMoveAxisClicked();
  void onRotateAxisClicked();
  void onMoveBtnClicked();
  void onRotateBtnClicked();
  void onScaleBtnClicked();
  void on_scaleToCenter_clicked();
  void on_scaleOptimize_clicked();
  void on_savePicture_clicked();
  void on_saveGif_toggled(bool checked);
  void takeScreen();

 private:
  Ui::MainWindow *ui;
  errors error;
  QString cfgName;
  QString currentDir;
  QGifImage *gif;
  void saveSettings();
  void loadSettings();
  void saveImage(QStringList mimeTypes);
};
#endif  // MAINWINDOW_H
