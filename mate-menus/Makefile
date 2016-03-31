# $NetBSD: Makefile,v 1.6 2015/04/09 20:38:31 krytarowski Exp $

DISTNAME=	mate-menus-1.12.0
CATEGORIES=	sysutils
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/releases/
COMMENT=	Implementation of the desktop menu specification for MATE
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libmenu/libmate-menu.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-menus

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/mate-menus/xdg/menus/mate-applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/mate-applications.menu
CONF_FILES+=	${PREFIX}/share/examples/mate-menus/xdg/menus/mate-settings.menu \
		${PKG_SYSCONFDIR}/xdg/menus/mate-settings.menu

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
