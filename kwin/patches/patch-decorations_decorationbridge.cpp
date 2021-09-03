$NetBSD$

changes from 5.18.5

--- decorations/decorationbridge.cpp	2018-05-02 00:52:19.000000000 +1200
+++ decorations/decorationbridge.cpp	2020-05-06 02:45:27.000000000 +1200
@@ -65,9 +65,17 @@
     : KDecoration2::DecorationBridge(parent)
     , m_factory(nullptr)
     , m_blur(false)
+    , m_showToolTips(false)
     , m_settings()
     , m_noPlugin(false)
 {
+    KConfigGroup cg(KSharedConfig::openConfig(), "KDE");
+
+    // try to extract the proper defaults file from a lookandfeel package
+    const QString looknfeel = cg.readEntry(QStringLiteral("LookAndFeelPackage"), "org.kde.breeze.desktop");
+    m_lnfConfig = KSharedConfig::openConfig(QStandardPaths::locate(QStandardPaths::GenericDataLocation, QStringLiteral("plasma/look-and-feel/") + looknfeel + QStringLiteral("/contents/defaults")));
+
+    readDecorationOptions();
 }
 
 DecorationBridge::~DecorationBridge()
@@ -75,9 +83,12 @@
     s_self = nullptr;
 }
 
-static QString readPlugin()
+QString DecorationBridge::readPlugin()
 {
-    return kwinApp()->config()->group(s_pluginName).readEntry("library", s_defaultPlugin);
+    //Try to get a default from look and feel
+    KConfigGroup cg(m_lnfConfig, "kwinrc");
+    cg = KConfigGroup(&cg, "org.kde.kdecoration2");
+    return kwinApp()->config()->group(s_pluginName).readEntry("library", cg.readEntry("library", s_defaultPlugin));
 }
 
 static bool readNoPlugin()
@@ -87,7 +98,15 @@
 
 QString DecorationBridge::readTheme() const
 {
-    return kwinApp()->config()->group(s_pluginName).readEntry("theme", m_defaultTheme);
+    //Try to get a default from look and feel
+    KConfigGroup cg(m_lnfConfig, "kwinrc");
+    cg = KConfigGroup(&cg, "org.kde.kdecoration2");
+    return kwinApp()->config()->group(s_pluginName).readEntry("theme", cg.readEntry("theme", m_defaultTheme));
+}
+
+void DecorationBridge::readDecorationOptions()
+{
+    m_showToolTips = kwinApp()->config()->group(s_pluginName).readEntry("ShowToolTips", true);
 }
 
 void DecorationBridge::init()
@@ -145,6 +164,8 @@
 
 void DecorationBridge::reconfigure()
 {
+    readDecorationOptions();
+
     if (m_noPlugin != readNoPlugin()) {
         m_noPlugin = !m_noPlugin;
         // no plugin setting changed
@@ -191,6 +212,7 @@
 {
     // reset all settings
     m_blur = false;
+    m_recommendedBorderSize = QString();
     m_theme = QString();
     m_defaultTheme = QString();
 
@@ -205,7 +227,13 @@
     if (blurIt != decoSettingsMap.end()) {
         m_blur = blurIt.value().toBool();
     }
+    auto recBorderSizeIt = decoSettingsMap.find(QStringLiteral("recommendedBorderSize"));
+    if (recBorderSizeIt != decoSettingsMap.end()) {
+        m_recommendedBorderSize = recBorderSizeIt.value().toString();
+    }
     findTheme(decoSettingsMap);
+
+    Q_EMIT metaDataLoaded();
 }
 
 void DecorationBridge::findTheme(const QVariantMap &map)
@@ -285,6 +313,7 @@
     QString b;
     b.append(QStringLiteral("Plugin: %1\n").arg(m_plugin));
     b.append(QStringLiteral("Theme: %1\n").arg(m_theme));
+    b.append(QStringLiteral("Plugin recommends border size: %1\n").arg(m_recommendedBorderSize.isNull() ? "No" : m_recommendedBorderSize));
     b.append(QStringLiteral("Blur: %1\n").arg(m_blur));
     const QMetaObject *metaOptions = m_settings->metaObject();
     for (int i=0; i<metaOptions->propertyCount(); ++i) {
