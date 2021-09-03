$NetBSD$

update to 5.18.5 version

--- kcmkwin/kwindecoration/declarative-plugin/previewclient.h	2018-05-02 00:52:19.000000000 +1200
+++ kcmkwin/kwindecoration/declarative-plugin/previewclient.h	2020-05-06 02:45:27.000000000 +1200
@@ -64,7 +64,7 @@
     Q_PROPERTY(bool bordersBottomEdge READ bordersBottomEdge WRITE setBordersBottomEdge NOTIFY bordersBottomEdgeChanged)
 public:
     explicit PreviewClient(DecoratedClient *client, Decoration *decoration);
-    virtual ~PreviewClient();
+    ~PreviewClient() override;
 
     QString caption() const override;
     WId decorationId() const override;
@@ -90,6 +90,7 @@
 
     int width() const override;
     int height() const override;
+    QSize size() const override;
     QPalette palette() const override;
     QColor color(ColorGroup group, ColorRole role) const override;
     Qt::Edges adjacentScreenEdges() const override;
@@ -97,8 +98,8 @@
     bool hasApplicationMenu() const override;
     bool isApplicationMenuActive() const override;
 
-    void requestShowToolTip(const QString &text);
-    void requestHideToolTip();
+    void requestShowToolTip(const QString &text) override;
+    void requestHideToolTip() override;
     void requestClose() override;
     void requestContextHelp() override;
     void requestToggleMaximization(Qt::MouseButtons buttons) override;
@@ -110,7 +111,7 @@
     void requestShowApplicationMenu(const QRect &rect, int actionId) override;
     void requestToggleOnAllDesktops() override;
 
-    void showApplicationMenu(int actionId);
+    void showApplicationMenu(int actionId) override;
 
     void setCaption(const QString &caption);
     void setActive(bool active);
