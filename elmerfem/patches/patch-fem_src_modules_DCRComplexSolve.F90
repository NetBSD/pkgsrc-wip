$NetBSD$

- Add local variable i so that it does not mix with the i in
  the outer scope.
  https://github.com/ElmerCSC/elmerfem/commit/96a33930ee23e785f33bcb257398f1ccca8fdf99.patch

- Fix a compilation error by adding i to local scope
  https://github.com/ElmerCSC/elmerfem/commit/8f9f2c703b020dc6d21cbaa1cb8b05abbbd7ded1.patch

--- fem/src/modules/DCRComplexSolve.F90.orig	2025-01-30 13:10:50.203031489 +0000
+++ fem/src/modules/DCRComplexSolve.F90
@@ -426,7 +426,7 @@ CONTAINS
    SUBROUTINE InputTensor( Tensor, IsScalar, Name, Material, n, NodeIndexes )
 !------------------------------------------------------------------------------
       REAL(KIND=dp) :: Tensor(:,:,:)
-      INTEGER :: n, NodeIndexes(:)
+      INTEGER :: i, n, NodeIndexes(:)
       LOGICAL :: IsScalar
       CHARACTER(LEN=*) :: Name
       TYPE(ValueList_t), POINTER :: Material
@@ -485,7 +485,8 @@ CONTAINS
 !------------------------------------------------------------------------------
       LOGICAL :: FirstTime = .TRUE., stat
       REAL(KIND=dp), POINTER :: Hwrk(:,:,:)
-
+      INTEGER :: i
+      
       SAVE FirstTime, Hwrk
 !------------------------------------------------------------------------------
       IF ( FirstTime ) THEN
@@ -1067,7 +1068,7 @@ contains
    SUBROUTINE InputVector( Tensor, IsScalar, Name, Material, n, NodeIndexes )
 !------------------------------------------------------------------------------
       REAL(KIND=dp) :: Tensor(:,:)
-      INTEGER :: n, NodeIndexes(:)
+      INTEGER :: i, n, NodeIndexes(:)
       LOGICAL :: IsScalar
       CHARACTER(LEN=*) :: Name
       TYPE(ValueList_t), POINTER :: Material
@@ -1367,7 +1368,7 @@ contains
    SUBROUTINE InputTensor( Tensor, IsScalar, Name, Material, n, NodeIndexes )
 !------------------------------------------------------------------------------
       REAL(KIND=dp) :: Tensor(:,:,:)
-      INTEGER :: n, NodeIndexes(:)
+      INTEGER :: i, n, NodeIndexes(:)
       LOGICAL :: IsScalar
       CHARACTER(LEN=*) :: Name
       TYPE(ValueList_t), POINTER :: Material
@@ -1419,7 +1420,7 @@ contains
    SUBROUTINE InputVector( Tensor, IsScalar, Name, Material, n, NodeIndexes )
 !------------------------------------------------------------------------------
       REAL(KIND=dp) :: Tensor(:,:)
-      INTEGER :: n, NodeIndexes(:)
+      INTEGER :: i, n, NodeIndexes(:)
       LOGICAL :: IsScalar
       CHARACTER(LEN=*) :: Name
       TYPE(ValueList_t), POINTER :: Material
@@ -1720,7 +1721,7 @@ CONTAINS
    SUBROUTINE InputTensor( Tensor, IsScalar, Name, Material, n, NodeIndexes )
 !------------------------------------------------------------------------------
       REAL(KIND=dp) :: Tensor(:,:,:)
-      INTEGER :: n, NodeIndexes(:)
+      INTEGER :: i, n, NodeIndexes(:)
       LOGICAL :: IsScalar
       CHARACTER(LEN=*) :: Name
       TYPE(ValueList_t), POINTER :: Material
@@ -1772,7 +1773,7 @@ CONTAINS
    SUBROUTINE InputVector( Tensor, IsScalar, Name, Material, n, NodeIndexes )
 !------------------------------------------------------------------------------
       REAL(KIND=dp) :: Tensor(:,:)
-      INTEGER :: n, NodeIndexes(:)
+      INTEGER :: i, n, NodeIndexes(:)
       LOGICAL :: IsScalar
       CHARACTER(LEN=*) :: Name
       TYPE(ValueList_t), POINTER :: Material
