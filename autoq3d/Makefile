# $NetBSD: Makefile,v 1.2 2012/09/26 23:15:55 othyro Exp $
#

DISTNAME=	AutoQ3DCommunity1-40qt4source
PKGNAME=	autoq3d-1.40
CATEGORIES=	cad
MASTER_SITES=	http://downloads.sourceforge.net/project/autoq3d/autoq3d/AutoQ3D%201.40/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.autoq3d.com/
COMMENT=	Application for computer aided drafting in two and dimensions
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/AutoQ3DCommunity1-40qt4source
USE_LANGUAGES=		c++

AUTOQ3D_DIR=		share/autoq3d
AUTOQ3D_HOME?=		${PREFIX}/${AUTOQ3D_DIR}

SUBST_CLASSES+=		autoq3d
SUBST_STAGE.autoq3d=	post-patch
SUBST_MESSAGE.autoq3d=	Fixing AUTOQ3D_HOME.
SUBST_FILES.autoq3d=	src/dialogs/prgsettings.cpp src/fgui/cadform.cpp
SUBST_FILES.autoq3d+=	src/main.cpp
SUBST_SED.autoq3d=	-e 's|/usr/share/AutoQ3D-Community|${AUTOQ3D_HOME}|'

MAKE_ENV+=		AUTOQ3D_HOME=${AUTOQ3D_HOME}

INSTALLATION_DIRS+=	bin ${AUTOQ3D_DIR}/images/ share/pixmaps

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} && ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AutoQ3D ${DESTDIR}${PREFIX}/bin/autoq3d
	${INSTALL_DATA} ${WRKSRC}/lan_sp.qm ${DESTDIR}${AUTOQ3D_HOME}/
	${INSTALL_DATA} ${WRKSRC}/lan_sp.ts ${DESTDIR}${AUTOQ3D_HOME}/
	${INSTALL_DATA} ${WRKSRC}/qref.htm ${DESTDIR}${AUTOQ3D_HOME}/
	${INSTALL_DATA} ${WRKSRC}/qref_sp.htm ${DESTDIR}${AUTOQ3D_HOME}/
	${INSTALL_DATA_DIR} ${DESTDIR}${AUTOQ3D_HOME}/images
	for a in `ls -1 ${WRKSRC}/images/*.png`; \
	do \
		${INSTALL_DATA} $$a ${DESTDIR}${AUTOQ3D_HOME}/images; \
        done
	${INSTALL_DATA} ${WRKSRC}/AutoQ3D.ico ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/AutoQ3D.png ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
