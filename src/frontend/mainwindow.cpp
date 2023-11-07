#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  error = OK;
  gif = nullptr;
  cfgName = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) +
            QDir::separator() + "3DViewer.cfg";
  currentDir = QDir::currentPath();
  connect(ui->moveBack, SIGNAL(clicked()), this, SLOT(onMoveBtnClicked()));
  connect(ui->moveForward, SIGNAL(clicked()), this, SLOT(onMoveBtnClicked()));
  connect(ui->rotateBack, SIGNAL(clicked()), this, SLOT(onRotateBtnClicked()));
  connect(ui->rotateForward, SIGNAL(clicked()), this,
          SLOT(onRotateBtnClicked()));
  connect(ui->scaleDown, SIGNAL(clicked()), this, SLOT(onScaleBtnClicked()));
  connect(ui->scaleUp, SIGNAL(clicked()), this, SLOT(onScaleBtnClicked()));
  connect(ui->rotateX, SIGNAL(clicked()), this, SLOT(onRotateAxisClicked()));
  connect(ui->rotateY, SIGNAL(clicked()), this, SLOT(onRotateAxisClicked()));
  connect(ui->rotateZ, SIGNAL(clicked()), this, SLOT(onRotateAxisClicked()));
  connect(ui->moveX, SIGNAL(clicked()), this, SLOT(onMoveAxisClicked()));
  connect(ui->moveY, SIGNAL(clicked()), this, SLOT(onMoveAxisClicked()));
  connect(ui->moveZ, SIGNAL(clicked()), this, SLOT(onMoveAxisClicked()));
  connect(ui->displayMethodNot, SIGNAL(clicked()), this,
          SLOT(onDispMethodClicked()));
  connect(ui->displayMethodSphere, SIGNAL(clicked()), this,
          SLOT(onDispMethodClicked()));
  connect(ui->displayMethodCube, SIGNAL(clicked()), this,
          SLOT(onDispMethodClicked()));
  loadSettings();
}

MainWindow::~MainWindow() {
  saveSettings();
  delete ui;
}

void MainWindow::on_pushButton_selectFile_clicked() {
  QFileDialog fileDialog(this);
  fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
  fileDialog.setFileMode(QFileDialog::AnyFile);
  fileDialog.setDirectory(currentDir);
  fileDialog.setNameFilters({"OBJ (*.obj)", "TXT (*.txt)"});
  if (fileDialog.exec()) {
    currentDir = fileDialog.directory().absolutePath();
    QList selectedFiles = fileDialog.selectedFiles();
    QString file = selectedFiles.first();
    error = ui->openGLWidget->getObjData(file);
    file = file.right(file.length() - file.lastIndexOf(QDir::separator()) - 1);
    if (error) {
      ui->statusbar->showMessage("Invalid file: " + file +
                                 "    Error: " + QString::number(error));
    } else {
      ui->statusbar->showMessage(
          "Filename: " + file +
          "    Vertexes: " + QString::number(ui->openGLWidget->getVnum()) +
          "    Faces: " + QString::number(ui->openGLWidget->getFnum()));
      error = ui->openGLWidget->optimizeView();
      if (!error) ui->openGLWidget->update();
    }
  }
}

void MainWindow::on_perspective_stateChanged(int arg1) {
  ui->openGLWidget->perspectiveProjection = (bool)arg1;
  ui->openGLWidget->update();
}

void MainWindow::on_edgeColorBtn_clicked() {
  ui->openGLWidget->eColor =
      QColorDialog::getColor(ui->openGLWidget->eColor, this);
  ui->openGLWidget->update();
}

void MainWindow::on_edgeThickBox_valueChanged(int arg1) {
  ui->openGLWidget->edgeThick = (size_t)arg1;
  ui->openGLWidget->update();
}

void MainWindow::on_edgeDashChk_stateChanged(int arg1) {
  ui->openGLWidget->dashedEdge = (bool)arg1;
  ui->openGLWidget->update();
}

void MainWindow::on_vColorBtn_clicked() {
  ui->openGLWidget->vColor =
      QColorDialog::getColor(ui->openGLWidget->vColor, this);
  ui->openGLWidget->update();
}

void MainWindow::on_vSizeBox_valueChanged(int arg1) {
  ui->openGLWidget->vSize = (size_t)arg1;
  ui->openGLWidget->update();
}

void MainWindow::onDispMethodClicked() {
  if (ui->displayMethodSphere->isChecked())
    ui->openGLWidget->setDisplayMethod(CIRCLE);
  else if (ui->displayMethodCube->isChecked())
    ui->openGLWidget->setDisplayMethod(SQUARE);
  else
    ui->openGLWidget->setDisplayMethod(NO);
  ui->openGLWidget->update();
}

void MainWindow::on_bgColorBtn_clicked() {
  ui->openGLWidget->bgColor =
      QColorDialog::getColor(ui->openGLWidget->bgColor, this);
  ui->openGLWidget->update();
}

void MainWindow::onMoveAxisClicked() {
  if (ui->moveY->isChecked())
    ui->openGLWidget->setShiftAxis(Y);
  else if (ui->moveZ->isChecked())
    ui->openGLWidget->setShiftAxis(Z);
  else
    ui->openGLWidget->setShiftAxis(X);
}

void MainWindow::onRotateAxisClicked() {
  if (ui->rotateY->isChecked())
    ui->openGLWidget->setRotationAxis(Y);
  else if (ui->rotateZ->isChecked())
    ui->openGLWidget->setRotationAxis(Z);
  else
    ui->openGLWidget->setRotationAxis(X);
}

void MainWindow::onMoveBtnClicked() {
  QPushButton *button = (QPushButton *)sender();
  double shift = ui->moveStep->value() / 100.0;
  if (button->objectName() == "moveBack") shift = -shift;
  error = ui->openGLWidget->moveModel(shift);
  ui->openGLWidget->update();
}

void MainWindow::onRotateBtnClicked() {
  QPushButton *button = (QPushButton *)sender();
  double angle = ui->rotateStep->value();
  if (button->objectName() == "rotateBack") angle = -angle;
  error = ui->openGLWidget->rotateModel(angle);
  ui->openGLWidget->update();
}

void MainWindow::onScaleBtnClicked() {
  QPushButton *button = (QPushButton *)sender();
  double scaleFactor = 1.0 - ui->scaleStep->value() / 100.0;
  if (button->objectName() == "scaleUp") scaleFactor = 1.0 / scaleFactor;
  error = ui->openGLWidget->scaleModel(scaleFactor);
  ui->openGLWidget->update();
}

void MainWindow::on_scaleToCenter_clicked() {
  error = ui->openGLWidget->centerModel();
  ui->openGLWidget->update();
}

void MainWindow::on_scaleOptimize_clicked() {
  error = ui->openGLWidget->optimizeView();
  ui->openGLWidget->update();
}

void MainWindow::saveSettings() {
  QByteArray ba = cfgName.toLocal8Bit();
  FILE *fd = fopen(ba.data(), "w");
  if (fd) {
    std::fprintf(
        fd, "%ld %ld %d %d %d %d %d %d %d %d %d %d %d %d",
        ui->openGLWidget->vSize, ui->openGLWidget->edgeThick,
        ui->openGLWidget->perspectiveProjection, ui->openGLWidget->dashedEdge,
        ui->openGLWidget->getDisplayMethod(), ui->openGLWidget->bgColor.red(),
        ui->openGLWidget->bgColor.green(), ui->openGLWidget->bgColor.blue(),
        ui->openGLWidget->eColor.red(), ui->openGLWidget->eColor.green(),
        ui->openGLWidget->eColor.blue(), ui->openGLWidget->vColor.red(),
        ui->openGLWidget->vColor.green(), ui->openGLWidget->vColor.blue());
    std::fclose(fd);
  }
}

void MainWindow::loadSettings() {
  QByteArray ba = cfgName.toLocal8Bit();
  FILE *fd = fopen(ba.data(), "r");
  if (fd) {
    ui->statusbar->showMessage("Настройки загружены из файла: " + cfgName);
    int perspProj, dashedEdge, displayMethod;
    int bgRed, bgGreen, bgBlue, eRed, eGreen, eBlue, vRed, vGreen, vBlue;
    std::fscanf(fd, "%ld %ld %d %d %d %d %d %d %d %d %d %d %d %d",
                &ui->openGLWidget->vSize, &ui->openGLWidget->edgeThick,
                &perspProj, &dashedEdge, &displayMethod, &bgRed, &bgGreen,
                &bgBlue, &eRed, &eGreen, &eBlue, &vRed, &vGreen, &vBlue);

    ui->openGLWidget->perspectiveProjection = (bool)perspProj;
    ui->openGLWidget->dashedEdge = (bool)dashedEdge;
    ui->openGLWidget->setDisplayMethod((displayMethods)displayMethod);
    ui->openGLWidget->bgColor = QColor::fromRgb(bgRed, bgGreen, bgBlue);
    ui->openGLWidget->eColor = QColor::fromRgb(eRed, eGreen, eBlue);
    ui->openGLWidget->vColor = QColor::fromRgb(vRed, vGreen, vBlue);

    ui->vSizeBox->setValue(ui->openGLWidget->vSize);
    ui->edgeThickBox->setValue(ui->openGLWidget->edgeThick);
    ui->perspective->setChecked((bool)perspProj);
    ui->edgeDashChk->setChecked((bool)dashedEdge);
    if (ui->openGLWidget->getDisplayMethod() == CIRCLE)
      ui->displayMethodSphere->setChecked(true);
    else if (ui->openGLWidget->getDisplayMethod() == SQUARE)
      ui->displayMethodCube->setChecked(true);
    else
      ui->displayMethodNot->setChecked(true);
    std::fclose(fd);
  }
}

void MainWindow::on_savePicture_clicked() {
  saveImage({"image/jpeg", "image/bmp"});
}

void MainWindow::saveImage(QStringList mimeTypes) {
  QFileDialog fileDialog(this);
  fileDialog.setAcceptMode(QFileDialog::AcceptSave);
  fileDialog.setFileMode(QFileDialog::AnyFile);
  fileDialog.setDirectory(
      QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));
  fileDialog.setMimeTypeFilters(mimeTypes);
  if (fileDialog.exec()) {
    QString selectedMime = fileDialog.selectedMimeTypeFilter();
    if (selectedMime == "image/gif")
      fileDialog.setDefaultSuffix("gif");
    else
      fileDialog.setDefaultSuffix(selectedMime == "image/jpeg" ? "jpg" : "bmp");
    QList selectedFiles = fileDialog.selectedFiles();
    QString file = selectedFiles.first();
    bool result = false;
    if (selectedMime == "image/gif")
      result = gif->save(file);
    else
      result = ui->openGLWidget->grabFramebuffer().save(file);
    if (!result)
      QMessageBox::warning(this, tr("Save Error"),
                           tr("The image could not be saved to %1.")
                               .arg(QDir::toNativeSeparators(file)));
  }
}

void MainWindow::on_saveGif_toggled(bool checked) {
  if (checked) {
    ui->saveGif->setText("Запись...");
    gif = new QGifImage;
    connect(ui->moveBack, SIGNAL(clicked()), this, SLOT(takeScreen()));
    connect(ui->moveForward, SIGNAL(clicked()), this, SLOT(takeScreen()));
    connect(ui->rotateBack, SIGNAL(clicked()), this, SLOT(takeScreen()));
    connect(ui->rotateForward, SIGNAL(clicked()), this, SLOT(takeScreen()));
    connect(ui->scaleDown, SIGNAL(clicked()), this, SLOT(takeScreen()));
    connect(ui->scaleUp, SIGNAL(clicked()), this, SLOT(takeScreen()));
    connect(ui->scaleToCenter, SIGNAL(clicked()), this, SLOT(takeScreen()));
    connect(ui->scaleOptimize, SIGNAL(clicked()), this, SLOT(takeScreen()));
  } else {
    disconnect(ui->moveBack, SIGNAL(clicked()), this, SLOT(takeScreen()));
    disconnect(ui->moveForward, SIGNAL(clicked()), this, SLOT(takeScreen()));
    disconnect(ui->rotateBack, SIGNAL(clicked()), this, SLOT(takeScreen()));
    disconnect(ui->rotateForward, SIGNAL(clicked()), this, SLOT(takeScreen()));
    disconnect(ui->scaleDown, SIGNAL(clicked()), this, SLOT(takeScreen()));
    disconnect(ui->scaleUp, SIGNAL(clicked()), this, SLOT(takeScreen()));
    disconnect(ui->scaleToCenter, SIGNAL(clicked()), this, SLOT(takeScreen()));
    disconnect(ui->scaleOptimize, SIGNAL(clicked()), this, SLOT(takeScreen()));
    saveImage({"image/gif"});
    delete gif;
    gif = nullptr;
    ui->saveGif->setText("Записать гифку");
  }
}

void MainWindow::takeScreen() {
  QImage img =
      ui->openGLWidget->grabFramebuffer().scaled(640, 480, Qt::KeepAspectRatio);
  gif->addFrame(img, 100);
}
