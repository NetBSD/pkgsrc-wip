# $NetBSD: Makefile,v 1.11 2011/06/30 21:38:41 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

DESKTOP_VERSION=4.8.2

DISTNAME=	xfdesktop-${DESKTOP_VERSION}
PKGNAME=	xfce4-desktop-${DESKTOP_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce desktop background manager

XFCE4_PROJECT=  	xfdesktop
XFCE4_BRANCH=		4.8

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

BUILD_DEFS+=	PKG_SYSCONFBASE

OWN_DIRS+=	${PKG_SYSCONFDIR}
MAKE_DIRS+=	${PREFIX}/lib/xfce4 ${PREFIX}/libexec/xfce4
MAKE_DIRS+=	${PREFIX}/libexec/panel-plugins ${XFCE4_EGBASE:Q}
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/doc
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/C ${PREFIX}/share/xfce4/doc/C/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/da
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/fr ${PREFIX}/share/xfce4/doc/fr/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/ja ${PREFIX}/share/xfce4/doc/ja/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/panel-plugins

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../wip/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/xfce4-thunar/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/garcon/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
