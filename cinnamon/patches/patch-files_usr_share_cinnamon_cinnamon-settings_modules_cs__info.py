$NetBSD$

Adapt for NetBSD

--- files/usr/share/cinnamon/cinnamon-settings/modules/cs_info.py.orig	2018-05-06 15:13:24.000000000 +0000
+++ files/usr/share/cinnamon/cinnamon-settings/modules/cs_info.py
@@ -36,14 +36,16 @@ def getGraphicsInfos():
     count = 0
     envpath = os.environ["PATH"]
     os.environ["PATH"] = envpath + ":/usr/local/sbin:/usr/sbin:/sbin"
-    for card in getProcessOut(("lspci")):
+    for card in getProcessOut(["pcictl", "/dev/pci0", "list"]):
         if not "VGA" in card:
             continue
-        cardId = card.split()[0]
+        cardN = card.split()[0]
+        cardId = cardN.split(":")[1]
+        cardFun = cardN.split(":")[2]
         cardName = None
-        for line in getProcessOut(("lspci", "-v", "-s", cardId)):
-            if line.startswith(cardId):
-                cardName = (line.split(":")[2].split("(rev")[0].strip())
+        for line in getProcessOut(("pcictl", "/dev/pci0", "list", "-d", cardId, "-f", cardFun)):
+            if line.startswith(cardN):
+                cardName = (line.split(":")[3].split("(VGA")[0].strip())
 
         if cardName:
             cards[count] = (cardName)
@@ -55,7 +57,7 @@ def getGraphicsInfos():
 def getDiskSize():
     disksize = 0
     moreThanOnce = 0
-    for line in getProcessOut(("df", "-l")):
+    for line in getProcessOut(("df", "-k")):
         if line.startswith("/dev/"):
             moreThanOnce += 1
             disksize += float(line.split()[1])
@@ -104,13 +106,13 @@ def createSystemInfos():
         title = ' '.join(contents[:2]) or "Manjaro Linux"
         infos.append((_("Operating System"), title))
     else:
-        s = '%s (%s)' % (' '.join(platform.linux_distribution()), arch)
+        s = '%s (%s)' % (platform.system(), arch)
         # Normalize spacing in distribution name
         s = re.sub('\s{2,}', ' ', s)
         infos.append((_("Operating System"), s))
     if 'CINNAMON_VERSION' in os.environ:
         infos.append((_("Cinnamon Version"), os.environ['CINNAMON_VERSION']))
-    infos.append((_("Linux Kernel"), platform.release()))
+    infos.append((_(platform.system() +  " Kernel"), platform.release()))
     infos.append((_("Processor"), processorName))
     if memunit == "kB":
         infos.append((_("Memory"), '%.1f %s' % ((float(memsize)/(1024*1024)), _("GiB"))))
