# $NetBSD$
#
# This file produces a Crystal compiler for bootstrapping by building
# the C/C++ components of Crystal, and linking them with the parts of
# the Crystal compiler written in Crystal (provided as a cross-built
# object).
#
# The standard Crystal build system expects a bootstrap compiler to
# exist in .build, so this Makefile gets used there.
#

LLVM_CFLAGS!=	llvm-config --cflags
LLVM_LIBS!=	llvm-config --libs

PKG_LIBS!=	pkg-config --libs bdw-gc \
			--libs libevent \
			--libs libpcre

CXXFLAGS+=	-std=c++14

all: crystal

crystal: crystal.o llvm_ext.o sigfault.o
	$(CC) $(LDFLAGS) $(LLVM_LIBS) $(PKG_LIBS) -o crystal crystal.o llvm_ext.o sigfault.o

llvm_ext.o: ../src/llvm/ext/llvm_ext.cc
	$(CXX) $(CXXFLAGS) $(LLVM_CFLAGS) -o llvm_ext.o -c ../src/llvm/ext/llvm_ext.cc

sigfault.o: ../src/ext/sigfault.c
	$(CC) $(CFLAGS) -o sigfault.o -c ../src/ext/sigfault.c
