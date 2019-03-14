$NetBSD$

--- ELF/Driver.h.orig	2019-03-14 17:33:43.000000000 +0000
+++ ELF/Driver.h
@@ -30,7 +30,9 @@ public:
   void addLibrary(StringRef Name);
 
 private:
+  void setTargetTriple(StringRef argv0, llvm::opt::InputArgList &Args);
   void readConfigs(llvm::opt::InputArgList &Args);
+  void appendDefaultSearchPaths();
   void createFiles(llvm::opt::InputArgList &Args);
   void inferMachineType();
   template <class ELFT> void link(llvm::opt::InputArgList &Args);
