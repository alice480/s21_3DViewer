#include "widgetogl.h"

size_t WidgetOGL::getVnum() { return ob.vnum; }

size_t WidgetOGL::getFnum() { return ob.fnum; }

void WidgetOGL::setRotationAxis(axes axis) { rotationAxis = axis; }

void WidgetOGL::setShiftAxis(axes axis) { shiftAxis = axis; }

void WidgetOGL::setDisplayMethod(displayMethods method) {
  displayMethod = method;
}

displayMethods WidgetOGL::getDisplayMethod() const { return displayMethod; }

WidgetOGL::WidgetOGL(QWidget *parent) : QOpenGLWidget(parent) {
  ob = {0};
  bgColor = QColor::fromRgb(0, 33, 55);
  eColor = QColor::fromRgb(245, 121, 0);
  vColor = QColor::fromRgb(146, 0, 10);
  vSize = 25;
  displayMethod = NO;
  perspectiveProjection = false;
  edgeThick = 4;
  dashedEdge = false;
  rotationAxis = X;
  shiftAxis = X;
}

WidgetOGL::~WidgetOGL() { free_obj(&ob); }

void WidgetOGL::initializeGL() {}

void WidgetOGL::paintGL() {
  glClearColor(bgColor.redF(), bgColor.greenF(), bgColor.blueF(), 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  double aspectRatio = this->width() / (double)this->height();
  if (perspectiveProjection) {
    glFrustum(-aspectRatio, aspectRatio, -1, 1, 1, 100);
    glTranslatef(0, 0, -2.1);
  } else
    glOrtho(-aspectRatio, aspectRatio, -1, 1, ob.zmin * 10, ob.zmax * 10);
  if (displayMethod && ob.vnum) drawVertexes();
  if (ob.fnum) drawLines();
}

void WidgetOGL::resizeGL(int w, int h) {}

void WidgetOGL::drawVertexes() {
  glColor3f(vColor.redF(), vColor.greenF(), vColor.blueF());
  glPointSize(vSize);
  displayMethod == CIRCLE ? glEnable(GL_POINT_SMOOTH)
                          : glDisable(GL_POINT_SMOOTH);
  glBegin(GL_POINTS);
  for (size_t i = 0; i < ob.vnum; ++i)
    glVertex3d(ob.vertexes[i].x, ob.vertexes[i].y, ob.vertexes[i].z);
  glEnd();
}

void WidgetOGL::drawLines() {
  glLineWidth(edgeThick);
  glColor3d(eColor.redF(), eColor.greenF(), eColor.blueF());
  if (dashedEdge) {
    glLineStipple(10, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
  } else
    glDisable(GL_LINE_STIPPLE);

  for (size_t i = 0; i < ob.fnum; ++i) {
    glBegin(GL_LINE_LOOP);
    for (size_t j = 0; j < ob.faces[i].num; j++)
      glVertex3f(ob.vertexes[ob.faces[i].vertexes[j]].x,
                 ob.vertexes[ob.faces[i].vertexes[j]].y,
                 ob.vertexes[ob.faces[i].vertexes[j]].z);
    glEnd();
  }
}

errors WidgetOGL::getObjData(QString fileName) {
  QByteArray ba = fileName.toLocal8Bit();
  free_obj(&ob);
  return make_obj(&ob, ba.data());
}

errors WidgetOGL::moveModel(double shift) {
  double xyz[3] = {0.0};
  xyz[shiftAxis] = shift;
  return move_obj(&ob, xyz);
}

errors WidgetOGL::rotateModel(double angle) {
  double xyz[3] = {0.0};
  xyz[rotationAxis] = angle;
  return rotate_obj(&ob, xyz);
}

errors WidgetOGL::scaleModel(double scaleFactor) {
  double xyz[3] = {scaleFactor, scaleFactor, scaleFactor};
  return scale_obj(&ob, xyz);
}

errors WidgetOGL::centerModel() {
  double xyz[3] = {0.0};
  xyz[0] = -(ob.xmax + ob.xmin) / 2;
  xyz[1] = -(ob.ymax + ob.ymin) / 2;
  xyz[2] = -(ob.zmax + ob.zmin) / 2;
  return move_obj(&ob, xyz);
}

errors WidgetOGL::optimizeView() {
  errors error = centerModel();
  if (!error) {
    double sizeX = ob.xmax - ob.xmin;
    double sizeY = ob.ymax - ob.ymin;
    double maxSize = sizeX > sizeY ? sizeX : sizeY;
    error = scaleModel(2 / maxSize);
  }
  return error;
}
