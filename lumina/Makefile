# $NetBSD$

DISTNAME=	lumina-0.8.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=pcbsd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}-Release

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lumina-desktop.org/
COMMENT=	Lumina Desktop Environment
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

DEPENDS+=	fluxbox-[0-9]*:../../wm/fluxbox
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver
DEPENDS+=	numlockx-[0-9]*:../../x11/numlockx
DEPENDS+=	xterm-[0-9]*:../../x11/xterm

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Fixing prefix
SUBST_FILES.prefix=	libLumina/LuminaXDG.cpp
SUBST_FILES.prefix+=	lumina-config/mainUI.cpp
SUBST_FILES.prefix+=	lumina-desktop/SettingsMenu.cpp
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},'

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	post-patch
SUBST_MESSAGE.sysconf=	Fixing system configuration dir
SUBST_FILES.sysconf=	libLumina/LuminaUtils.cpp
SUBST_SED.sysconf=	-e 's,/etc/luminaDesktop.conf,${PKG_SYSCONFDIR}/luminaDesktop.conf,'

INSTALL_ENV=		INSTALL_ROOT=${DESTDIR}

pre-build:
	${RUN} cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${PREFIX} CONFIG+="configure NO_I18N"

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
