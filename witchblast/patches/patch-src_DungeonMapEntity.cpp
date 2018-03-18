$NetBSD$

Search the installation directories for data files.

--- src/DungeonMapEntity.cpp.orig	2015-10-29 08:36:26.000000000 +0000
+++ src/DungeonMapEntity.cpp
@@ -848,16 +848,16 @@ void DungeonMapEntity::computeVertices()
     switch (roomType)
     {
     case roomTypeChallenge:
-      ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile("media/overlay_boss_01.png");
+      ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile(WITCHBLAST_DATA_DIR "media/overlay_boss_01.png");
       break;
     case roomTypeTemple:
-      ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile("media/overlay_temple.png");
+      ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile(WITCHBLAST_DATA_DIR "media/overlay_temple.png");
       break;
     case roomTypeMerchant:
-      ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile("media/overlay_shop.png");
+      ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile(WITCHBLAST_DATA_DIR "media/overlay_shop.png");
       break;
     case roomTypeBoss:
-      ss << "media/overlay_boss_0" << game().getLevel() << ".png";
+      ss << WITCHBLAST_DATA_DIR "media/overlay_boss_0" << game().getLevel() << ".png";
       ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile(ss.str());
       break;
     default:
@@ -868,9 +868,9 @@ void DungeonMapEntity::computeVertices()
            || gameMap->getObjectTile(8, 2) == MAPOBJ_BANK
            || gameMap->getObjectTile(8, 2) == MAPOBJ_BANK_BOTTOM
          )
-        ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile("media/overlay_temple.png");
+        ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile(WITCHBLAST_DATA_DIR "media/overlay_temple.png");
       else
-        ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile("media/overlay_00.png");
+        ImageManager::getInstance().getImage(IMAGE_OVERLAY)->loadFromFile(WITCHBLAST_DATA_DIR "media/overlay_00.png");
       break;
     }
     overlaySprite.setTexture(*ImageManager::getInstance().getImage(IMAGE_OVERLAY));
