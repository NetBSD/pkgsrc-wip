$NetBSD$

changes from 5.18.5

--- decorations/decoratedclient.cpp	2018-05-02 00:52:19.000000000 +1200
+++ decorations/decoratedclient.cpp	2020-05-06 02:45:27.000000000 +1200
@@ -18,6 +18,7 @@
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *********************************************************************/
 #include "decoratedclient.h"
+#include "decorationbridge.h"
 #include "decorationpalette.h"
 #include "decorationrenderer.h"
 #include "abstract_client.h"
@@ -31,6 +32,8 @@
 #include <KDecoration2/Decoration>
 
 #include <QDebug>
+#include <QStyle>
+#include <QToolTip>
 
 namespace KWin
 {
@@ -64,6 +67,7 @@
             if (oldSize.height() != m_clientSize.height()) {
                 emit decoratedClient->heightChanged(m_clientSize.height());
             }
+            emit decoratedClient->sizeChanged(m_clientSize);
         }
     );
     connect(client, &AbstractClient::desktopChanged, this,
@@ -85,10 +89,9 @@
             &Decoration::DecoratedClientImpl::signalShadeChange);
     connect(client, &AbstractClient::keepAboveChanged, decoratedClient, &KDecoration2::DecoratedClient::keepAboveChanged);
     connect(client, &AbstractClient::keepBelowChanged, decoratedClient, &KDecoration2::DecoratedClient::keepBelowChanged);
+    connect(Compositor::self(), &Compositor::aboutToToggleCompositing, this, &DecoratedClientImpl::destroyRenderer);
     m_compositorToggledConnection = connect(Compositor::self(), &Compositor::compositingToggled, this,
         [this, decoration]() {
-            delete m_renderer;
-            m_renderer = nullptr;
             createRenderer();
             decoration->update();
         }
@@ -113,9 +116,25 @@
 
     connect(client, &AbstractClient::hasApplicationMenuChanged, decoratedClient, &KDecoration2::DecoratedClient::hasApplicationMenuChanged);
     connect(client, &AbstractClient::applicationMenuActiveChanged, decoratedClient, &KDecoration2::DecoratedClient::applicationMenuActiveChanged);
+
+    m_toolTipWakeUp.setSingleShot(true);
+    connect(&m_toolTipWakeUp, &QTimer::timeout, this,
+            [this]() {
+                int fallAsleepDelay = QApplication::style()->styleHint(QStyle::SH_ToolTip_FallAsleepDelay);
+                this->m_toolTipFallAsleep.setRemainingTime(fallAsleepDelay);
+
+                QToolTip::showText(Cursor::pos(), this->m_toolTipText);
+                m_toolTipShowing = true;
+            }
+    );
 }
 
-DecoratedClientImpl::~DecoratedClientImpl() = default;
+DecoratedClientImpl::~DecoratedClientImpl()
+{
+    if (m_toolTipShowing) {
+        requestHideToolTip();
+    }
+}
 
 void DecoratedClientImpl::signalShadeChange() {
     emit decoratedClient()->shadedChanged(m_client->isShade());
@@ -202,11 +221,21 @@
 
 void DecoratedClientImpl::requestShowToolTip(const QString &text)
 {
-    Q_UNUSED(text)
+    if (!DecorationBridge::self()->showToolTips()) {
+        return;
+    }
+
+    m_toolTipText = text;
+
+    int wakeUpDelay = QApplication::style()->styleHint(QStyle::SH_ToolTip_WakeUpDelay);
+    m_toolTipWakeUp.start(m_toolTipFallAsleep.hasExpired() ? wakeUpDelay : 20);
 }
 
 void DecoratedClientImpl::requestHideToolTip()
 {
+    m_toolTipWakeUp.stop();
+    QToolTip::hideText();
+    m_toolTipShowing = false;
 }
 
 void DecoratedClientImpl::requestShowWindowMenu()
@@ -245,5 +274,10 @@
     return m_clientSize.height();
 }
 
+QSize DecoratedClientImpl::size() const
+{
+    return m_clientSize;
+}
+
 bool DecoratedClientImpl::isMaximizedVertically() const
 {
