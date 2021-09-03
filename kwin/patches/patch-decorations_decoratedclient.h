$NetBSD$

changes from 5.18.5

--- decorations/decoratedclient.h	2018-05-02 00:52:19.000000000 +1200
+++ decorations/decoratedclient.h	2020-05-06 02:45:27.000000000 +1200
@@ -23,7 +23,9 @@
 
 #include <KDecoration2/Private/DecoratedClientPrivate>
 
+#include <QDeadlineTimer>
 #include <QObject>
+#include <QTimer>
 
 namespace KWin
 {
@@ -40,7 +42,7 @@
     Q_OBJECT
 public:
     explicit DecoratedClientImpl(AbstractClient *client, KDecoration2::DecoratedClient *decoratedClient, KDecoration2::Decoration *decoration);
-    virtual ~DecoratedClientImpl();
+    ~DecoratedClientImpl() override;
     QString caption() const override;
     WId decorationId() const override;
     int desktop() const override;
@@ -64,6 +66,7 @@
     QPalette palette() const override;
     QColor color(KDecoration2::ColorGroup group, KDecoration2::ColorRole role) const override;
     bool providesContextHelp() const override;
+    QSize size() const override;
     int width() const override;
     WId windowId() const override;
 
@@ -72,8 +75,8 @@
     bool hasApplicationMenu() const override;
     bool isApplicationMenuActive() const override;
 
-    void requestShowToolTip(const QString &text);
-    void requestHideToolTip();
+    void requestShowToolTip(const QString &text) override;
+    void requestHideToolTip() override;
     void requestClose() override;
     void requestContextHelp() override;
     void requestToggleMaximization(Qt::MouseButtons buttons) override;
@@ -85,7 +88,7 @@
     void requestToggleOnAllDesktops() override;
     void requestToggleShade() override;
 
-    void showApplicationMenu(int actionId);
+    void showApplicationMenu(int actionId) override;
 
     AbstractClient *client() {
         return m_client;
@@ -93,7 +96,6 @@
     Renderer *renderer() {
         return m_renderer;
     }
-    void destroyRenderer();
     KDecoration2::DecoratedClient *decoratedClient() {
         return KDecoration2::DecoratedClientPrivate::client();
     }
@@ -105,10 +107,16 @@
 
 private:
     void createRenderer();
+    void destroyRenderer();
     AbstractClient *m_client;
     QSize m_clientSize;
     Renderer *m_renderer;
     QMetaObject::Connection m_compositorToggledConnection;
+
+    QString m_toolTipText;
+    QTimer m_toolTipWakeUp;
+    QDeadlineTimer m_toolTipFallAsleep;
+    bool m_toolTipShowing = false;
 };
 
 }
