# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

.include "Makefile.common"

PKGNAME=	llvm-${LLVM_VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
GCC_REQD+=		4.8
PYTHON_FOR_BUILD_ONLY=	yes

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_LINK_FLAGS=${LDFLAGS:Q}
CMAKE_ARGS+=	-DLLVM_BUILD_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_INSTALL_UTILS=ON
#CMAKE_ARGS+=	-DLLVM_LINK_LLVM_DYLIB=ON

CMAKE_ARGS.Darwin+=	-DCMAKE_LIBTOOL=/usr/bin/libtool

TEST_TARGET=		check
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

# It may be that the Solaris linker is more strict here and they can be removed on
# all platforms.  Change this to a patch if verified.
SUBST_CLASSES.SunOS+=	lto
SUBST_STAGE.lto=	pre-configure
SUBST_FILES.lto=	tools/lto/lto.exports
SUBST_SED.lto=		-e '/^LLVM/d'

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	notdylib
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SOEXT=		dylib
.else
SOEXT=		so
PLIST.notdylib=	yes
.endif
PLIST_SUBST+=	SOEXT=${SOEXT}

# needs std::atomic with 64-bit CAS
.if ${MACHINE_ARCH} == "i386"
CXXFLAGS+=	-march=i586
.endif

.include "options.mk"

# replacing config.guess is required even for cmake.
# It is used to detect correct LLVM_HOST_TRIPLE, e.g. for NetBSD/evbarm.
post-extract:
	${RUN} mkdir -p ${WRKDIR}/build
.for f in config.guess config.sub
	cp ../../mk/gnu-config/${f} ${WRKSRC}/cmake/${f}
.endfor

.include "../../wip/mk/git-package.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
