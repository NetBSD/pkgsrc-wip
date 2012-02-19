# $NetBSD: Makefile,v 1.13 2012/02/19 17:41:51 guigui2 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

UTILS_VERSION=	4.8.3

DISTNAME=	xfce-utils-${UTILS_VERSION}
PKGNAME=	xfce4-utils-${UTILS_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce utilities

XFCE4_PROJECT=  	xfce-utils
XFCE4_BRANCH=		4.8

DEPENDS+=	p5-XML-Parser>=2.36:../../textproc/p5-XML-Parser

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--with-xsession-prefix=${PREFIX}

BUILD_DEFS+=		PKG_SYSCONFBASE
USE_TOOLS+=		xinit:run

PKG_SYSCONFSUBDIR=	xdg
EGDIR=			${XFCE4_EGBASE}

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${EGDIR} ${EGDIR}/autostart
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/doc
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/C ${PREFIX}/share/xfce4/doc/C/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/fr ${PREFIX}/share/xfce4/doc/it
MAKE_DIRS+=	${PREFIX}/share/xsessions

CONF_FILES=		${EGDIR}/xinitrc ${PKG_SYSCONFDIR}/xfce4/xinitrc
CONF_FILES+=		${EGDIR}/autostart/xfconf-migration-4.6.desktop \
			${PKG_SYSCONFDIR}/autostart/xfconf-migration-4.6.desktop

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
