$NetBSD$

some changes from 5.18.5

--- plugins/qpa/integration.cpp.orig	2018-05-01 12:52:19.000000000 +0000
+++ plugins/qpa/integration.cpp
@@ -99,7 +99,11 @@ void Integration::initialize()
     );
     QPlatformIntegration::initialize();
     auto dummyScreen = new Screen(-1);
+#if (QT_VERSION >= QT_VERSION_CHECK(5, 13, 0))
+    QWindowSystemInterface::handleScreenAdded(dummyScreen);
+#else
     screenAdded(dummyScreen);
+#endif
     m_screens << dummyScreen;
     m_inputContext.reset(QPlatformInputContextFactory::create(QStringLiteral("qtvirtualkeyboard")));
     qunsetenv("QT_IM_MODULE");
@@ -205,13 +209,31 @@ QPlatformOpenGLContext *Integration::cre
 void Integration::initScreens()
 {
     QVector<Screen*> newScreens;
+    newScreens.reserve(qMax(screens()->count(), 1));
     for (int i = 0; i < screens()->count(); i++) {
         auto screen = new Screen(i);
+#if (QT_VERSION >= QT_VERSION_CHECK(5, 13, 0))
+        QWindowSystemInterface::handleScreenAdded(screen);
+#else
         screenAdded(screen);
+#endif
         newScreens << screen;
     }
+    if (newScreens.isEmpty()) {
+        auto dummyScreen = new Screen(-1);
+#if (QT_VERSION >= QT_VERSION_CHECK(5, 13, 0))
+        QWindowSystemInterface::handleScreenAdded(dummyScreen);
+#else
+        screenAdded(dummyScreen);
+#endif
+        newScreens << dummyScreen;
+    }
     while (!m_screens.isEmpty()) {
+#if (QT_VERSION >= QT_VERSION_CHECK(5, 13, 0))
+        QWindowSystemInterface::handleScreenRemoved(m_screens.takeLast());
+#else
         destroyScreen(m_screens.takeLast());
+#endif
     }
     m_screens = newScreens;
 }
