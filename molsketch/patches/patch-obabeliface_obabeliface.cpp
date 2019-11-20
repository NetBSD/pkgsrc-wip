$NetBSD$

--- obabeliface/obabeliface.cpp.orig	2019-03-13 20:46:48.000000000 +0000
+++ obabeliface/obabeliface.cpp
@@ -48,6 +48,9 @@
 #include <openbabel/canon.h>
 #endif
 
+#include <openbabel/obiter.h>
+#include <openbabel/bond.h>
+#include <openbabel/elements.h>
 #include <openbabel/mol.h>
 #include <openbabel/data.h>
 #include <openbabel/obconversion.h>
@@ -55,20 +58,18 @@
 #include <openbabel/op.h>
 #include <openbabel/stereo/stereo.h>
 
-OpenBabel::OBElementTable eTable ;
-
 namespace Molsketch
 {
   static const char INCHI_FORMAT[] = "inchi";
 
   QString number2symbol( int number )
   {
-    return eTable.GetSymbol(number);
+    return OpenBabel::OBElements::GetSymbol(number);
   }
 
   int symbol2number( const QString &symbol )
   {
-    return eTable.GetAtomicNum(symbol.STRINGCONVERSION) ;
+    return OpenBabel::OBElements::GetAtomicNum(symbol.STRINGCONVERSION) ;
   }
 
   OpenBabel::OBMol toOBMolecule(const Molsketch::Molecule* originalMolecule, unsigned short int dim = 2)
@@ -353,8 +354,8 @@ namespace Molsketch
       using namespace OpenBabel;
     // Remove any existing wedge and hash bonds
     FOR_BONDS_OF_MOL(b, &mol)  {
-      b->UnsetWedge();
-      b->UnsetHash();
+      b->SetWedge(false);
+      b->SetHash(false);
     }
 
     std::map<OBBond*, enum OBStereo::BondDirection> updown;
