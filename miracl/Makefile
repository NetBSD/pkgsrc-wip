# $NetBSD: Makefile,v 1.3 2012/10/03 15:09:55 asau Exp $
#

DISTNAME=	miracl
PKGNAME=	${DISTNAME}-${PKGVERSION}
PKGVERSION=	5.4
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.computing.dcu.ie/pub/crypto/
EXTRACT_SUFX=	.zip

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://www.shamus.ie
COMMENT=	Multiprecision Integer and Rational Arithmetic C/C++ Library

INSTALLATION_DIRS+=	include/${DISTNAME}
#BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

EXTRACT_OPTS_ZIP+=	-j -aa -L -d ${DISTNAME}

USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
BUILDCMD =		linux
.elif ${MACHINE_ARCH} == "x86_64"
BUILDCMD =		linux64
.else
PKG_FAIL_REASON=	"This package is unavailable on your machine"
.endif

SUBST_CLASSES+=		script
SUBST_STAGE.script=	post-patch
SUBST_SED.script=	-e 's|gcc|${CC}|'
SUBST_SED.script+=	-e 's|g\+\+|${CXX}|'
.if ${MACHINE_ARCH} == "i386"
SUBST_SED.script+=	-e 's|-O2|${CFLAGS}|'
.elif ${MACHINE_ARCH} == "x86_64"
SUBST_SED.script+=	-e 's|-O2|${CFLAGS} -fPIC|'
.endif
SUBST_FILES.script=	${BUILDCMD}
SUBST_MESSAGE.script=	Fixing hardcoded compiler options

PLIST_SUBST+=	DISTNAME=${DISTNAME}
do-build:
	cd ${WRKSRC} && ${SH} ./${BUILDCMD}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.a ${PREFIX}/lib/lib${DISTNAME}.a
	#${INSTALL_DATA_DIR}	${PREFIX}/include/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/miracl.h ${PREFIX}/include/${DISTNAME}/miracl.h
	${INSTALL_DATA} ${WRKSRC}/mirdef.h ${PREFIX}/include/${DISTNAME}/mirdef.h

.include "../../mk/bsd.pkg.mk"
