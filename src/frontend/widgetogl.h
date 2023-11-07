#ifndef WIDGETOGL_H
#define WIDGETOGL_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "backend/v3d.h"

typedef enum displayMethods { NO, CIRCLE, SQUARE } displayMethods;
typedef enum axes { X, Y, Z } axes;

class WidgetOGL : public QOpenGLWidget {
  Q_OBJECT
 public:
  QColor bgColor, eColor, vColor;
  size_t vSize, edgeThick;
  bool perspectiveProjection, dashedEdge;

  explicit WidgetOGL(QWidget *parent = nullptr);
  ~WidgetOGL();
  errors getObjData(QString fileName);
  errors moveModel(double shift);
  errors rotateModel(double angle);
  errors scaleModel(double scaleFactor);
  errors centerModel();
  errors optimizeView();
  size_t getVnum();
  size_t getFnum();
  void setRotationAxis(axes axis);
  void setShiftAxis(axes axis);
  void setDisplayMethod(displayMethods method);
  displayMethods getDisplayMethod() const;

 private:
  obj ob;
  axes rotationAxis, shiftAxis;
  displayMethods displayMethod;

  void paintGL() override;
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void drawVertexes();
  void drawLines();
};

#endif  // WIDGETOGL_H
