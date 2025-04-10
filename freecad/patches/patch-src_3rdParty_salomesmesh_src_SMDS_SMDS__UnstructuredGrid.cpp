$NetBSD$

Fix build for vtk 9.4:
https://github.com/FreeCAD/FreeCAD/commit/3b502359353e2a74dee8a8bcfed5750b69f32cdc

--- src/3rdParty/salomesmesh/src/SMDS/SMDS_UnstructuredGrid.cpp.orig	2025-04-10 08:44:05.488258553 +0000
+++ src/3rdParty/salomesmesh/src/SMDS/SMDS_UnstructuredGrid.cpp
@@ -32,6 +32,7 @@
 #include <vtkDoubleArray.h>
 #include <vtkIdTypeArray.h>
 #include <vtkUnsignedCharArray.h>
+#include <vtkVersionMacros.h>
 
 #include <list>
 #include <climits>
@@ -249,14 +250,16 @@ void SMDS_UnstructuredGrid::compactGrid(
     }
   }
 
-  if (this->FaceLocations)
+  vtkIdTypeArray* thisFaceLocations = GetFaceLocations();
+  vtkIdTypeArray* thisFaces = GetFaces();
+  if (thisFaceLocations)
     {
       vtkIdTypeArray *newFaceLocations = vtkIdTypeArray::New();
       newFaceLocations->Initialize();
       newFaceLocations->Allocate(newTypes->GetSize());
       vtkIdTypeArray *newFaces = vtkIdTypeArray::New();
       newFaces->Initialize();
-      newFaces->Allocate(this->Faces->GetSize());
+      newFaces->Allocate(thisFaces->GetSize());
       for (int i = 0; i < oldCellSize; i++)
         {
           if (this->Types->GetValue(i) == VTK_EMPTY_CELL)
@@ -265,16 +268,16 @@ void SMDS_UnstructuredGrid::compactGrid(
           if (newTypes->GetValue(newCellId) == VTK_POLYHEDRON)
             {
                newFaceLocations->InsertNextValue(newFaces->GetMaxId()+1);
-               int oldFaceLoc = this->FaceLocations->GetValue(i);
-               int nCellFaces = this->Faces->GetValue(oldFaceLoc++);
+               int oldFaceLoc = thisFaceLocations->GetValue(i);
+               int nCellFaces = thisFaces->GetValue(oldFaceLoc++);
                newFaces->InsertNextValue(nCellFaces);
                for (int n=0; n<nCellFaces; n++)
                  {
-                   int nptsInFace = this->Faces->GetValue(oldFaceLoc++);
+                   int nptsInFace = thisFaces->GetValue(oldFaceLoc++);
                    newFaces->InsertNextValue(nptsInFace);
                    for (int k=0; k<nptsInFace; k++)
                      {
-                       int oldpt = this->Faces->GetValue(oldFaceLoc++);
+                       int oldpt = thisFaces->GetValue(oldFaceLoc++);
                        newFaces->InsertNextValue(idNodesOldToNew[oldpt]);
                      }
                  }
@@ -292,7 +295,7 @@ void SMDS_UnstructuredGrid::compactGrid(
     }
   else
   {
-    this->SetCells(newTypes, newLocations, newConnectivity, FaceLocations, Faces);
+    this->SetCells(newTypes, newLocations, newConnectivity, thisFaceLocations, thisFaces);
   }
 
   newPoints->Delete();
