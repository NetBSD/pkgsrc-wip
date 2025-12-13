# $NetBSD$

DISTNAME=	sway-1.11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=swaywm/}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://swaywm.org/
COMMENT=	Tilling, i3-compatible Wayland compositor
LICENSE=	mit

USE_TOOLS+=	pkg-config
TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

EGDIR=		${PREFIX}/share/examples/sway
OWN_DIRS+=	${PKG_SYSCONFDIR}/sway
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/sway/config

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/man7

post-install:
	scdoc < ${WRKSRC}/sway/sway.1.scd > ${WRKSRC}/sway/sway.1
	scdoc < ${WRKSRC}/sway/sway.5.scd > ${WRKSRC}/sway/sway.5
	scdoc < ${WRKSRC}/sway/sway-bar.5.scd > ${WRKSRC}/sway/sway-bar.5
	scdoc < ${WRKSRC}/sway/sway-input.5.scd > ${WRKSRC}/sway/sway-input.5
	scdoc < ${WRKSRC}/sway/sway-ipc.7.scd > ${WRKSRC}/sway/sway-ipc.7
	scdoc < ${WRKSRC}/sway/sway-output.5.scd > ${WRKSRC}/sway/sway-output.5
	scdoc < ${WRKSRC}/swaynag/swaynag.1.scd > ${WRKSRC}/swaynag/swaynag.1
	scdoc < ${WRKSRC}/swaynag/swaynag.5.scd > ${WRKSRC}/swaynag/swaynag.5
	scdoc < ${WRKSRC}/swaybar/swaybar-protocol.7.scd > ${WRKSRC}/swaybar/swaybar-protocol.7
	scdoc < ${WRKSRC}/swaymsg/swaymsg.1.scd > ${WRKSRC}/swaymsg/swaymsg.1
	${INSTALL_MAN} ${WRKSRC}/sway/sway.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sway.1
	${INSTALL_MAN} ${WRKSRC}/sway/sway.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/sway.5
	${INSTALL_MAN} ${WRKSRC}/sway/sway-bar.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/sway-bar.5
	${INSTALL_MAN} ${WRKSRC}/sway/sway-input.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/sway-input.5
	${INSTALL_MAN} ${WRKSRC}/sway/sway-ipc.7 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/sway-ipc.7
	${INSTALL_MAN} ${WRKSRC}/sway/sway-output.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/sway-output.5
	${INSTALL_MAN} ${WRKSRC}/swaynag/swaynag.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/swaynag.1
	${INSTALL_MAN} ${WRKSRC}/swaynag/swaynag.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/swaynag.5
	${INSTALL_MAN} ${WRKSRC}/swaybar/swaybar-protocol.7 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/swaybar-protocol.7
	${INSTALL_MAN} ${WRKSRC}/swaymsg/swaymsg.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/swaymsg.1
	${INSTALL_SCRIPT} ${FILESDIR}/startsway.sh \
		${DESTDIR}${PREFIX}/bin/startsway


.include "../../wip/wlroots/buildlink3.mk"
.include "../../wip/libevdev-chunk/buildlink3.mk"
.include "../../wip/basu/buildlink3.mk"
.include "../../wip/seatd/buildlink3.mk"

.include "../../devel/meson/build.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
