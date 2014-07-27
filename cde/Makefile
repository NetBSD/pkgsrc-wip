# $NetBSD: Makefile,v 1.10 2014/07/27 05:40:04 obache Exp $
#
DISTNAME=	cde-src-2.2.1
PKGNAME=	${DISTNAME:S/-src-/-/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdesktopenv/}

MAINTAINER=	jelle@jellehermsen.nl
HOMEPAGE=	http://cdesktopenv.sourceforge.net/
COMMENT=	Common Desktop Environment
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=     bison bdftopcf mkfontdir ksh
BUILD_TARGET=	World

MAKE_JOBS_SAFE=	no

DEPENDS+= ast-ksh-[0-9]*:../../shells/ast-ksh

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

PKG_SYSCONFSUBDIR=	dt

CFLAGS+=		-I${X11BASE}/include/X11

IMAKE_DEFINES+=		-DCplusplusCmd=${CXX}
IMAKE_DEFINES+=		-DLibraryCplusplusCmd=${CXX}
IMAKE_DEFINES+=		-DX11ProjectRoot=${X11BASE}
IMAKE_DEFINES+=		-DProjectRoot=${PREFIX}
IMAKE_DEFINES+=		-DTopMotifInclude=${MOTIFBASE}/include
IMAKE_DEFINES+=		-DCDEProjectRoot=${PREFIX}/dt
IMAKE_DEFINES+=		-DCdeInstallationTop=${PREFIX}/dt
IMAKE_DEFINES+=		-DCdeConfigurationTop=${PKG_SYSCONFDIR}
IMAKE_DEFINES+=		-DCdeLogfileTop=${VARBASE}/dt
#IMAKE_DEFINES+=		-DTclLibrary=${BUILDLINK_PREFIX.tcl}/lib
IMAKE_DEFINES+=		-DUseInstalledX11=YES
#IMAKE_DEFINES+=	-DKornShell=${TOOLS_PATH.ksh}
BUILD_MAKE_FLAGS+=	BOOTSTRAPCFLAGS=${CFLAGS:Q}
BUILD_MAKE_FLAGS+=	IMAKE_DEFINES=${IMAKE_DEFINES:Q}
#MAKE_ENV+=		MFLAGS=KORNSHELL=${TOOLS_PATH.ksh}

BUILD_DEFS+=		VARBASE
OWN_DIRS+=		${VARBASE}/dt

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-configure
SUBST_FILES.destdir=	admin/IntegTools/dbTools/installCDE.src
SUBST_SED.destdir=	-e 's,-D / ,-D $$DESTDIR ,'

do-install:
	${RUN}cd ${WRKSRC}/admin/IntegTools/dbTools; \
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ./installCDE -s ${WRKSRC}

.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
#.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
