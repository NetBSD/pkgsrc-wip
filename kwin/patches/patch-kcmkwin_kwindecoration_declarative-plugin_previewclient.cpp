$NetBSD$

update to 5.18.5 version

--- kcmkwin/kwindecoration/declarative-plugin/previewclient.cpp	2018-05-02 00:52:19.000000000 +1200
+++ kcmkwin/kwindecoration/declarative-plugin/previewclient.cpp	2020-05-06 02:45:27.000000000 +1200
@@ -69,7 +69,6 @@
     connect(this, &PreviewClient::maximizedVerticallyChanged,   c, &DecoratedClient::maximizedVerticallyChanged);
     connect(this, &PreviewClient::maximizedHorizontallyChanged, c, &DecoratedClient::maximizedHorizontallyChanged);
     connect(this, &PreviewClient::minimizableChanged,           c, &DecoratedClient::minimizeableChanged);
-//         connect(this, &PreviewClient::modalChanged, c, &DecoratedClient::modalChanged);
     connect(this, &PreviewClient::movableChanged,               c, &DecoratedClient::moveableChanged);
     connect(this, &PreviewClient::onAllDesktopsChanged,         c, &DecoratedClient::onAllDesktopsChanged);
     connect(this, &PreviewClient::resizableChanged,             c, &DecoratedClient::resizeableChanged);
@@ -81,7 +80,6 @@
     connect(this, &PreviewClient::heightChanged,                c, &DecoratedClient::heightChanged);
     connect(this, &PreviewClient::iconChanged,                  c, &DecoratedClient::iconChanged);
     connect(this, &PreviewClient::paletteChanged,               c, &DecoratedClient::paletteChanged);
-//         connect(this, &PreviewClient::, c, &DecoratedClient::);
     connect(this, &PreviewClient::maximizedVerticallyChanged, this,
         [this]() {
             emit maximizedChanged(isMaximized());
@@ -113,6 +111,11 @@
     connect(this, &PreviewClient::bordersLeftEdgeChanged,   this, emitEdgesChanged);
     connect(this, &PreviewClient::bordersRightEdgeChanged,  this, emitEdgesChanged);
     connect(this, &PreviewClient::bordersBottomEdgeChanged, this, emitEdgesChanged);
+    auto emitSizeChanged = [this, c]() {
+        emit c->sizeChanged(c->size());
+    };
+    connect(this, &PreviewClient::widthChanged, this, emitSizeChanged);
+    connect(this, &PreviewClient::heightChanged, this, emitSizeChanged);
 
     qApp->installEventFilter(this);
 }
@@ -135,6 +138,11 @@
     return m_height;
 }
 
+QSize PreviewClient::size() const
+{
+    return QSize(m_width, m_height);
+}
+
 QString PreviewClient::caption() const
 {
     return m_caption;
@@ -353,7 +361,7 @@
 
 void PreviewClient::requestShowToolTip(const QString &text)
 {
-    Q_UNUSED(text)
+    Q_UNUSED(text);
 }
 
 void PreviewClient::requestHideToolTip()
@@ -367,7 +375,6 @@
 
 void PreviewClient::requestContextHelp()
 {
-    qDebug() << "context help requested";
 }
 
 void PreviewClient::requestToggleMaximization(Qt::MouseButtons buttons)
@@ -430,7 +437,6 @@
     if (m_##variable == variable) { \
         return; \
     } \
-    qDebug() << "Setting " << #variable << ":" << variable;\
     m_##variable = variable; \
     emit variable##Changed(m_##variable); \
 }
