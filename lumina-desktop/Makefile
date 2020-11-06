# $NetBSD$

DISTNAME=	lumina-1.6.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lumina-desktop/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lumina-desktop.org/
COMMENT=	Lightweight desktop for Unix-like operating systems
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

EGDIR=		${PREFIX}/share/examples/lumina
CONF_FILES+=	${EGDIR}/luminaDesktop.conf ${PKG_SYSCONFDIR}/luminaDesktop.conf

MAKE_ENV+=	LFLAGS=${LDFLAGS:Q}

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake PREFIX=${PREFIX} LIBPREFIX=${PREFIX}/lib \
	L_ETCDIR=${PKG_SYSCONFDIR} L_MANDIR=${PREFIX}/${PKGMANDIR} \
	CONFIG+="configure WITH_I18N" ${EXTRA}

pre-install:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${RUN} ${INSTALL_DATA} ${WRKSRC}/src-qt5/core/lumina-desktop/defaults/luminaDesktop.conf ${DESTDIR}${EGDIR}

post-install:
	${RUN} ${RM} -f ${DESTDIR}${PREFIX}/share/lumina-desktop/menu-scripts/ls.json.sh.orig
	${RUN} ${RM} -f ${DESTDIR}${PREFIX}/etc/luminaDesktop.conf.dist

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
DEPENDS+=	fluxbox-[0-9]*:../../wm/fluxbox
DEPENDS+=	numlockx-[0-9]*:../../x11/numlockx
DEPENDS+=	pavucontrol-[0-9]*:../../audio/pavucontrol
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/xscreensaver/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
