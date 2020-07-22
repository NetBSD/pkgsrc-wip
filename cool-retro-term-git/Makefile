# $NetBSD$

PKGNAME=		cool-retro-term-1.1.1
CATEGORIES=		x11

MAINTAINER=		stix@stix.id.au
HOMEPAGE=		https://github.com/Swordfish90/cool-retro-term
COMMENT=		Terminal emulator which mimics old cathode display artifacts
LICENSE=		gnu-gpl-v3

# For non-pkgsrc/wip:
#MASTER_SITES=		${MASTER_SITE_GITHUB:=Swordfish90/}
#TERM_TAG=		1.1.1
#QMLTERMWIDGET_TAG=	0.2.0
#DISTFILES+=		${TERM_TAG}.tar.gz
#DISTFILES+=		${QMLTERMWIDGET_TAG}.tar.gz
#DIST_SUBDIR=		cool-retro-term
#SITES.${TERM_TAG}.tar.gz= \
#	${MASTER_SITE_GITHUB:=Swordfish90/cool-retro-term/archive/}
#SITES.${QMLTERMWIDGET_TAG}.tar.gz= \
#	${MASTER_SITE_GITHUB:=Swordfish90/qmltermwidget/archive/}
#WRKSRC=			${WRKDIR}/cool-retro-term-${TERM_TAG}

# For pkgsrc/wip:
PKGREVISION=
GIT_REPOSITORIES=	cool-retro-term
GIT_REPO.cool-retro-term=	git://github.com/Swordfish90/cool-retro-term.git
GIT_TAG.cool-retro-term=	1.1.1
WRKSRC=			${WRKDIR}/cool-retro-term

SUBST_CLASSES+=		usrpath
SUBST_STAGE.usrpath=	pre-configure
SUBST_FILES.usrpath+=	app/app.pro
SUBST_FILES.usrpath+=	cool-retro-term.pro
SUBST_SED.usrpath=	-e "s|/usr/|/usr/pkg/|g"

DEPENDS+=		qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

USE_LANGUAGES=		c c++
USE_TOOLS+=		pax
MAKE_FLAGS+=		INSTALL_ROOT=${DESTDIR} sysconfdir=${PREFIX}/share

# For non-pkgsrc/wip:
#post-extract:
#	# Move git submodule into the correct location.
#	${MV} ${WRKDIR}/qmltermwidget-${QMLTERMWIDGET_TAG}/* ${WRKSRC}/qmltermwidget/

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
