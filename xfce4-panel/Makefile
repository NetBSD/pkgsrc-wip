# $NetBSD: Makefile,v 1.21 2012/02/19 17:09:59 guigui2 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

DISTNAME=		xfce4-panel-4.8.6
CATEGORIES=		x11
COMMENT=		Xfce panel

XFCE4_PROJECT=  	xfce4-panel
XFCE4_BRANCH=		4.8

PKGCONFIG_OVERRIDE=	libxfce4panel/libxfce4panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

EGDIR=			${XFCE4_EGBASE}/panel
PKG_SYSCONFSUBDIR=	xdg
CONF_FILES+=	${EGDIR}/default.xml \
				${PKG_SYSCONFDIR}/xfce4/panel/default.xml

MAKE_DIRS+=		${PKG_SYSCONFDIR}/xfce4/panel
#MAKE_DIRS+=	${PREFIX}/include/xfce4 ${PREFIX}/lib/xfce4
#MAKE_DIRS+=	${XFCE4_EGBASE:Q} ${PREFIX}/share/xfce4
#MAKE_DIRS+=	${PREFIX}/share/xfce4/doc ${PREFIX}/share/xfce4/doc/C
#MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/C/images
#OWN_DIRS+=	${PKG_SYSCONFDIR}
#OWN_DIRS+=	${PREFIX}/libexec/xfce4/panel-plugins
# The following are not used in this pkg, but here is a good place to rmdir them
#MAKE_DIRS+=	${PREFIX}/libexec/xfce4
#OWN_DIRS+=	${PREFIX}/share/xfce4/panel-plugins


.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/xfce4-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/garcon/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
#.include "../../x11/startup-notification/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
