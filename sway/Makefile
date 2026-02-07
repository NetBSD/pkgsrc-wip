# $NetBSD$

DISTNAME=	sway-1.11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=swaywm/}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://swaywm.org/
COMMENT=	Tilling, i3-compatible Wayland compositor
LICENSE=	mit

USE_TOOLS+=	pkg-config

EGDIR=		${PREFIX}/share/examples/sway
OWN_DIRS+=	${PKG_SYSCONFDIR}/sway
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/sway/config

#CFLAGS+=		-O0 -g
#INSTALL_UNSTRIPPED=	yes

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/startsway.sh \
		${DESTDIR}${PREFIX}/bin/startsway


.include "../../wip/wlroots/buildlink3.mk"
.include "../../wip/libevdev-chunk/buildlink3.mk"
.include "../../wip/basu/buildlink3.mk"
.include "../../wip/seatd/buildlink3.mk"

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
