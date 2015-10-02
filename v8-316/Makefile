# $NetBSD: Makefile,v 1.2 2014/08/25 13:22:01 fhajny Exp $

DISTNAME=		v8-3.16.14
CATEGORIES=		lang
MASTER_SITES=		http://gsdview.appspot.com/chromium-browser-official/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		msporleder@gmail.com
COMMENT=		V8 JavaScript Engine
HOMEPAGE=		http://code.google.com/p/v8
LICENSE=		modified-bsd

BUILD_DEPENDS+=		${PYPKGPREFIX}-gyp-[0-9]*:../../devel/gyp

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake:run

USE_MULTIARCH=		yes

NO_CONFIGURE=		yes
BUILD_TARGET=		native
TEST_TARGET=		native.check

.include "../../mk/bsd.prefs.mk"

# This reveals the actual commands run under gyp/make control
MAKE_ENV+=		V=1
MAKE_ENV+=		GYPFLAGS=-Dtarget_arch=${MACHINE_ARCH:S/i386/ia32/:S/x86_64/x64/}

MAKE_FLAGS+=		console=readline
MAKE_FLAGS+=		library=shared
MAKE_FLAGS+=		werror=no

CPPFLAGS.SunOS+=	-fPIC

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Fix default paths
SUBST_FILES.path=	tools/gyp/v8.gyp
SUBST_SED.path=		-e 's,/usr/pkg,${PREFIX},g'
SUBST_SED.path+=	-e 's,/usr/local,${PREFIX},g'

REPLACE_PYTHON=		tools/*.py tools/*/*.py tools/*/*/*.py
REPLACE_PYTHON+=	third_party/icu/source/*/*.py
REPLACE_PYTHON+=	third_party/icu/source/*/*/*.py

INSTALLATION_DIRS+=	bin include lib${LIBARCHSUFFIX}

INSTALL_INCLUDES=	v8-debug.h v8-preparser.h v8-profiler.h
INSTALL_INCLUDES+=	v8-testing.h v8.h
INSTALL_INCLUDES+=	v8stdint.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/native/d8 ${DESTDIR}${PREFIX}/bin/d8
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
	${INSTALL_LIB} ${WRKSRC}/out/native/libv8.dylib ${DESTDIR}${PREFIX}/lib/libv8.1.dylib
	${LN} -sf libv8.1.dylib ${DESTDIR}${PREFIX}/lib/libv8.dylib
.else
	${INSTALL_LIB} ${WRKSRC}/out/native/lib.target/libv8.so ${DESTDIR}${PREFIX}/lib${LIBARCHSUFFIX}/libv8.so.1
	${LN} -sf libv8.so.1 ${DESTDIR}${PREFIX}/lib${LIBARCHSUFFIX}/libv8.so
.endif
.for inc in ${INSTALL_INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/include/${inc} ${DESTDIR}${PREFIX}/include
.endfor

.include "../../devel/gyp/tool.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
