# $NetBSD: Makefile,v 1.37 2015/08/22 10:50:15 roelants Exp $
#

DISTVERSION=	0.17.5
DISTNAME=	enlightenment-${DISTVERSION}
PKGNAME=	e17-${DISTVERSION:S/-//}
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2
PKGREVISION=	1

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	https://www.enlightenment.org/
COMMENT=	The Window Manager and Desktop Shell
LICENSE=	2-clause-bsd

#DEPENDS+=	evas-gif>=1.7.0:../../wip/evas-gif
#DEPENDS+=	evas-gl-x11>=1.7.0:../../wip/evas-gl-x11
DEPENDS+=	evas-software-x11>=1.7.0:../../wip/evas-software-x11
DEPENDS+=	evas-xpm>=1.7.0:../../wip/evas-xpm
DEPENDS+=	evas_generic_loaders>=1.7.0:../../wip/evas_generic_loaders17

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE=	enlightenment.pc.in \
			src/modules/everything/everything.pc.in

CONFIGURE_ARGS+=	--disable-device-hal --disable-device-udev \
			--disable-mount-hal --disable-mount-udisks

PKG_SYSCONFSUBDIR=	enlightenment
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/enlightenment
CONF_FILES=		${EGDIR}/sysactions.conf \
			${PKG_SYSCONFDIR}/sysactions.conf \
			${EGDIR}/xdg/menus/enlightenment.menu \
			${PKG_SYSCONFBASE}/xdg/menus/enlightenment.menu

MAKE_DIRS=		${PKG_SYSCONFBASE}/xdg/menus

BUILD_DEFS+=	PKG_SYSCONFBASE

MODULE_ARCH=		${LOWER_OPSYS}${APPEND_ELF}-${MACHINE_GNU_ARCH}
PLIST_SUBST=		MODULE_ARCH=${MODULE_ARCH:Q} \
			DISTVERSION=${DISTVERSION:Q}
PRINT_PLIST_AWK+=	{ gsub(/${MODULE_ARCH}/, "$${MODULE_ARCH}"); \
			  gsub(/${DISTVERSION}/, "$${DISTVERSION}"); }

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../wip/embryo/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/e_dbus/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../wip/elementary17/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
