# $NetBSD$

DISTNAME=	labwc-0.9.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=labwc/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://labwc.github.io/
COMMENT=	Wlroots-based compositor for Wayland, inspired by Openbox
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

EGDIR=		${PREFIX}/share/examples/labwc
CONF_FILES=	${EGDIR}/autostart ${PKG_SYSCONFDIR}/autostart
CONF_FILES+=	${EGDIR}/environment ${PKG_SYSCONFDIR}/environment
CONF_FILES+=	${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/menu.xml
CONF_FILES+=	${EGDIR}/rc.xml ${PKG_SYSCONFDIR}/rc.xml
CONF_FILES+=	${EGDIR}/rc.xml.all ${PKG_SYSCONFDIR}/rc.xml.all
CONF_FILES+=	${EGDIR}/shutdown ${PKG_SYSCONFDIR}/shutdown
CONF_FILES+=	${EGDIR}/themerc ${PKG_SYSCONFDIR}/themerc

PKG_SYSCONFSUBDIR=	xdg/labwc
INSTALL_MAKE_FLAGS+=	rcdir=${EGDIR}

# Fix: [../src/main.c:94] no fonts are available
DEPENDS+=		nerd-fonts-Hack-[0-9]*:../../fonts/nerd-fonts-Hack

CFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../wip/modular-xorg-xwayland/buildlink3.mk"

.include "../../wip/libsfdo/buildlink3.mk"
.include "../../wip/wlroots/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
