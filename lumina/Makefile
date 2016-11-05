# $NetBSD$
PKGNAME=	lumina-1.1.0
DISTNAME=	lumina-qt5-1.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=trueos/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
DEPENDS+=	libxcb-[0-9]*:../../x11/libxcb
DEPENDS+=	libXdamage-[0-9]*:../../x11/libXdamage

INSTALL_MAKE_FLAGS=		INSTALL_ROOT=${DESTDIR}

pre-build:
	${RUN} cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${PREFIX} CONFIG+="configure WITH_I18N"

pre-install:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${RUN} ${INSTALL_DATA} ${WRKSRC}/src-qt5/core/lumina-desktop/defaults/luminaDesktop.conf ${DESTDIR}${EGDIR}

.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
