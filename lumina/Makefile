# $NetBSD$

DISTNAME=	lumina-0.9.0
PATCHREL=	-P1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=pcbsd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}-Release${PATCHREL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lumina-desktop.org/
COMMENT=	Lumina Desktop Environment
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

USE_LIBTOOL=	yes

EGDIR=		${PREFIX}/share/examples/lumina

CONF_FILES+=	${EGDIR}/luminaDesktop.conf ${PKG_SYSCONFDIR}/luminaDesktop.conf

DEPENDS+=	fluxbox-[0-9]*:../../wm/fluxbox
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver
DEPENDS+=	numlockx-[0-9]*:../../x11/numlockx

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_MESSAGE.prefix=	Fixing prefix
SUBST_FILES.prefix=	libLumina/LuminaXDG.cpp
SUBST_FILES.prefix+=	lumina-config/mainUI.cpp
SUBST_FILES.prefix+=	lumina-desktop/SettingsMenu.cpp
SUBST_FILES.prefix+=	libLumina/LuminaOS-NetBSD.cpp
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},'

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	post-patch
SUBST_MESSAGE.sysconf=	Fixing system configuration dir
SUBST_FILES.sysconf=	libLumina/LuminaUtils.cpp
SUBST_SED.sysconf=	-e 's,/etc/luminaDesktop.conf,${PKG_SYSCONFDIR}/luminaDesktop.conf,'

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	post-patch
SUBST_MESSAGE.egdir=	Install configuration to example dir
SUBST_FILES.egdir=	lumina-desktop/lumina-desktop.pro
SUBST_SED.egdir=	-e 's,\$\$PREFIX/etc/luminaDesktop.conf.dist,${EGDIR}/luminaDesktop.conf,'

INSTALL_MAKE_FLAGS=		INSTALL_ROOT=${DESTDIR}

# The NO_I18N option results in regeneration of empty translation files
# These files are available via lumina-i18n
pre-build:
	${RUN} cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${PREFIX} CONFIG+="configure NO_I18N"

pre-install:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${RUN} ${INSTALL_DATA} ${WRKSRC}/lumina-desktop/defaults/luminaDesktop.conf ${DESTDIR}${EGDIR}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
