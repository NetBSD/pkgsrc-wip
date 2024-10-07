$NetBSD$

# Portability

--- rules.mak.orig	2020-05-25 20:52:22.000000000 +0000
+++ rules.mak
@@ -12,23 +12,18 @@ ifndef CXX
 CXX      := g++
 endif
 
-ifneq (,$(findstring /,$(shell whereis ccache)))
-CXX      := ccache $(CXX)
-endif
-
 CFLAGS   += --std=c++2a
 CFLAGS   += -fno-strict-aliasing -fexceptions -fPIC
 CFLAGS   += -fdata-sections -ffunction-sections
 CFLAGS   += -funsigned-char
+CFLAGS   += -Wno-deprecated-declarations
 
-LFLAGS   += -Wl,--gc-sections
-LFLAGS   += -rdynamic
-
-XLIBS    += -lstdc++fs
+LDFLAGS   += -Wl,--gc-sections
+LDFLAGS   += -rdynamic
 
 WARNINGS := -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
 WARNINGS += -Wno-implicit-fallthrough
-WARNINGS += -Wno-maybe-uninitialized
+WARNINGS += -Wno-uninitialized
 WARNINGS += -Wcast-qual
 
 INCLUDES := -I../../include
@@ -41,20 +36,16 @@ ifeq ($(CFG),Debug)
 DEBUG    := 1
 endif
 
-ifdef ARCH
-CFLAGS   += -march=$(ARCH)
-endif
-
 ifdef LTO
 CFLAGS   += -flto
-LFLAGS   += -flto
+LDFLAGS   += -flto
 endif
 
 ifdef DEBUG
 CFLAGS   += -g3 -O0 -DDEBUG
 else
 CFLAGS   += -g3 -O3 -fomit-frame-pointer
-LFLAGS   += -g3 -O3
+LDFLAGS   += -g3 -O3
 endif
 
 ifdef LOGGER
@@ -74,12 +65,17 @@ endif
 
 ifeq ($(OSTYPE),Linux)
 OS       := OS_LINUX
+XLIBS	 += -lstdc++fs
 endif
 
 ifeq ($(OSTYPE),FreeBSD)
 OS       := OS_LINUX
 endif
 
+ifeq ($(OSTYPE),NetBSD)
+OS       := OS_LINUX
+endif
+
 ifeq ($(OSTYPE),Darwin)
 CXX      := c++
 OS       := OS_MACOSX
@@ -102,20 +98,20 @@ CFLAGS   += -D$(OS)
 DF        = $(CFG)/$(*F)
 
 $(CFG)/%.o : %.cpp
-	@echo $<
-	@$(CXX) -c $(CFLAGS) $(WARNINGS) $(INCLUDES) -MD -o $@ $<
-	@cp $(DF).d $(DF).dep; \
+	echo $<
+	$(CXX) -c $(CFLAGS) $(WARNINGS) $(INCLUDES) -MD -o $@ $<
+	cp $(DF).d $(DF).dep; \
 		sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
 			-e '/^$$/ d' -e 's/$$/ :/' < $(DF).d >> $(DF).dep; \
 		rm -f $(DF).d
 
 $(CFG)/%.o : %.m
-	@echo $<
-	@$(CC) -c $(CFLAGS) $(WARNINGS) $(INCLUDES) -o $@ $<
+	echo $<
+	$(CC) -c $(CFLAGS) $(WARNINGS) $(INCLUDES) -o $@ $<
 
 %.h.gch: %.h
-	@echo Generating pre-compiled header for $<
-	@$(CXX) $(CFLAGS) $(WARNINGS) $(INCLUDES) $<
+	echo Generating pre-compiled header for $<
+	$(CXX) $(CFLAGS) $(WARNINGS) $(INCLUDES) $<
 
 .SUFFIXES: .cpp .c .o
 
