$NetBSD$

changes from 5.18.5

--- decorations/decorationbridge.h	2018-05-02 00:52:19.000000000 +1200
+++ decorations/decorationbridge.h	2020-05-06 02:45:27.000000000 +1200
@@ -24,6 +24,8 @@
 
 #include <KDecoration2/Private/DecorationBridge>
 
+#include <KSharedConfig>
+
 #include <QObject>
 #include <QSharedPointer>
 
@@ -42,11 +44,11 @@
 namespace Decoration
 {
 
-class DecorationBridge : public KDecoration2::DecorationBridge
+class KWIN_EXPORT DecorationBridge : public KDecoration2::DecorationBridge
 {
     Q_OBJECT
 public:
-    virtual ~DecorationBridge();
+    ~DecorationBridge() override;
 
     void init();
     KDecoration2::Decoration *createDecoration(AbstractClient *client);
@@ -58,6 +60,13 @@
     bool needsBlur() const {
         return m_blur;
     }
+    QString recommendedBorderSize() const {
+        return m_recommendedBorderSize;
+    }
+
+    bool showToolTips() const {
+        return m_showToolTips;
+    }
 
     void reconfigure();
 
@@ -67,13 +76,21 @@
 
     QString supportInformation() const;
 
+Q_SIGNALS:
+    void metaDataLoaded();
+
 private:
+    QString readPlugin();
     void loadMetaData(const QJsonObject &object);
     void findTheme(const QVariantMap &map);
     void initPlugin();
     QString readTheme() const;
+    void readDecorationOptions();
     KPluginFactory *m_factory;
+    KSharedConfig::Ptr m_lnfConfig;
     bool m_blur;
+    bool m_showToolTips;
+    QString m_recommendedBorderSize;
     QString m_plugin;
     QString m_defaultTheme;
     QString m_theme;
