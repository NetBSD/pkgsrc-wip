# $NetBSD$

VERSION=	2019.8.2
DISTNAME=	Retro68-${VERSION}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=autc04/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/autc04/Retro68/
COMMENT=	M68k cross compiler environment
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		pkg-config gmake
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++ fortran

#RKSRC=		${WRKDIR}/${DISTNAME}
CPPFLAGS+=	-Iinclude/libhfs
CFLAGS+=	-Ihfsutils/libhfs

# check-portability
SUBST_CLASSES=		equal-test
SUBST_STAGE.equal-test=	pre-configure
SUBST_SED.equal-test=	'-e s," == "," = " ,'
SUBST_FILES.equal-test=	\
	binutils/binutils/testsuite/binutils-all/dlltool.exp \
	binutils/binutils/testsuite/binutils-all/objcopy.exp \
	binutils/gas/testsuite/lib/gas-defs.exp \
	binutils/ld/pe-dll.c \
	binutils/ld/scripttempl/elfarc.sc \
	binutils/ld/scripttempl/elfarcv2.sc \
	binutils/ld/testsuite/ChangeLog-2012 \
	binutils/ld/testsuite/ld-bootstrap/bootstrap.exp \
	binutils/ld/testsuite/ld-elf/binutils.exp \
	binutils/ld/testsuite/ld-x86-64/x86-64.exp \
	binutils/ld/testsuite/lib/ld-lib.exp \
	binutils/opcodes/bfin-dis.c \
	gcc/contrib/ChangeLog \
	gcc/contrib/dg-extract-results.sh \
	gcc/contrib/download_prerequisites \
	gcc/contrib/reghunt/bin/reg-hunt \
	gcc/contrib/repro_fail \
	gcc/gcc/ada/repinfo.adb \
	gcc/gcc/ada/xeinfo.adb \
	gcc/gcc/d/dmd/hdrgen.c \
	gcc/gcc/genattrtab.c \
	gcc/gcc/go/gofrontend/expressions.cc \
	gcc/gcc/testsuite/gcc.dg/pr28685-1.c \
	gcc/gcc/testsuite/gcc.dg/tree-ssa/forwprop-15.c \
	gcc/gcc/testsuite/gcc.target/s390/s390.exp \
	gcc/gcc/testsuite/gcc.test-framework/gen_directive_tests \
	gcc/gcc/testsuite/gdc.test/compilable/fix17335.d \
	gcc/gcc/testsuite/gdc.test/compilable/interpret3.d \
	gcc/gcc/testsuite/gdc.test/runnable/constfold.d \
	gcc/gcc/testsuite/gdc.test/runnable/template4.d \
	gcc/gcc/testsuite/gdc.test/runnable/test12.d \
	gcc/gcc/testsuite/go.test/go-test.exp \
	gcc/gcc/testsuite/go.test/test/fixedbugs/bug425.go \
	gcc/gcc/testsuite/jit.dg/jit.exp \
	gcc/gcc/testsuite/lib/asan-dg.exp \
	gcc/gcc/testsuite/lib/gcc-defs.exp \
	gcc/gcc/testsuite/lib/gcc-dg.exp \
	gcc/gcc/testsuite/lib/objc.exp \
	gcc/gcc/testsuite/lib/target-supports.exp \
	gcc/libatomic/testsuite/lib/libatomic.exp \
	gcc/libffi/testsuite/lib/libffi.exp \
	gcc/libgo/go/go/constant/value_test.go \
	gcc/libgo/go/go/types/eval_test.go \
	gcc/libgo/go/html/template/js.go \
	gcc/libgo/go/html/template/js_test.go \
	gcc/libgo/go/net/http/h2_bundle.go \
	gcc/libgo/go/runtime/runtime_test.go \
	gcc/libgo/mksysinfo.sh \
	gcc/libgomp/testsuite/lib/libgomp.exp \
	gcc/libitm/testsuite/lib/libitm.exp \
	gcc/libphobos/libdruntime/core/time.d \
	gcc/libphobos/src/std/conv.d \
	gcc/libphobos/src/std/regex/internal/kickstart.d \
	gcc/libphobos/src/std/variant.d \
	gcc/libstdc++-v3/doc/html/manual/appendix_porting.html \
	gcc/libstdc++-v3/doc/xml/manual/build_hacking.xml \
	gcc/libstdc++-v3/include/bits/locale_facets.tcc \
	gcc/libstdc++-v3/testsuite/22_locale/collate/compare/char/2.cc \
	gcc/libstdc++-v3/testsuite/22_locale/collate/compare/wchar_t/2.cc \
	gcc/libstdc++-v3/testsuite/22_locale/collate/hash/char/2.cc \
	gcc/libstdc++-v3/testsuite/22_locale/collate/hash/wchar_t/2.cc \
	gcc/libstdc++-v3/testsuite/22_locale/collate/transform/char/2.cc \
	gcc/libstdc++-v3/testsuite/22_locale/collate/transform/wchar_t/2.cc \
	gcc/libstdc++-v3/testsuite/22_locale/collate_byname/named_equivalence.cc \
	gcc/libstdc++-v3/testsuite/lib/libstdc++.exp \
	gcc/libvtv/testsuite/lib/libvtv.exp



PKGCONFIG_OVERRIDE+=	binutils/zlib/contrib/minizip/minizip.pc.in
PKGCONFIG_OVERRIDE+=	binutils/zlib/zlib.pc.in
PKGCONFIG_OVERRIDE+=	gcc/libffi/libffi.pc.in
PKGCONFIG_OVERRIDE+=	gcc/zlib/contrib/minizip/minizip.pc.in
PKGCONFIG_OVERRIDE+=	gcc/zlib/zlib.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libhfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
