# $NetBSD$

PKGVERSION=		1.2.0
PKGNAME=		cool-retro-term-${PKGVERSION}
CATEGORIES=		x11

MAINTAINER=		stix@stix.id.au
HOMEPAGE=		https://github.com/Swordfish90/cool-retro-term
COMMENT=		Terminal emulator which mimics old cathode display artifacts
LICENSE=		gnu-gpl-v3

MASTER_SITES=		${MASTER_SITE_GITHUB:=Swordfish90/}
TERM_TAG=		${PKGVERSION}
QMLTERMWIDGET_TAG=	63228027e1f97c24abb907550b22ee91836929c5
DISTFILES+=		${TERM_TAG}.tar.gz
DISTFILES+=		${QMLTERMWIDGET_TAG}.tar.gz
DIST_SUBDIR=		cool-retro-term
SITES.${TERM_TAG}.tar.gz= \
			${MASTER_SITE_GITHUB:=Swordfish90/cool-retro-term/archive/}
SITES.${QMLTERMWIDGET_TAG}.tar.gz= \
			${MASTER_SITE_GITHUB:=Swordfish90/qmltermwidget/archive/}
WRKSRC=			${WRKDIR}/cool-retro-term-${TERM_TAG}

SUBST_CLASSES+=		usrpath
SUBST_STAGE.usrpath=	pre-configure
SUBST_FILES.usrpath+=	app/app.pro
SUBST_FILES.usrpath+=	cool-retro-term.pro
SUBST_SED.usrpath=	-e "s|/usr/|${PREFIX}/|g"

DEPENDS+=		qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

ICON_THEMES=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pax
MAKE_FLAGS+=		INSTALL_ROOT=${DESTDIR} sysconfdir=${PREFIX}/share

post-extract:
	# Move git submodule into the correct location.
	${MV} ${WRKDIR}/qmltermwidget-${QMLTERMWIDGET_TAG}/* ${WRKSRC}/qmltermwidget/

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
