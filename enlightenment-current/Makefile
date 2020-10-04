# $NetBSD: Makefile,v 0.2 2018/09/06 16:15:10 andyb Exp $

DISTNAME=	enlightenment-0.24.2
PKGNAME=	${DISTNAME:S/enlightenment/enlightenment-current/}
CATEGORIES=	wm
PKGREVISION=	1
MASTER_SITES=	https://download.enlightenment.org/rel/apps/enlightenment/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://www.enlightenment.org/
COMMENT=	The Enlightenment window manager
LICENSE=	2-clause-bsd

CONFLICTS=	enlightenment-[0-9]*

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/modules/everything/everything.pc.in

EGDIR=		${PREFIX}/share/examples/enlightenment
CONF_FILES=	${EGDIR}/sysactions.conf \
		${PKG_SYSCONFDIR}/enlightenment/sysactions.conf
CONF_FILES+=	${EGDIR}/system.conf \
		${PKG_SYSCONFDIR}/enlightenment/system.conf
CONF_FILES+=	${EGDIR}/e-applications.menu \
		${PKG_SYSCONFBASE}/xdg/menus/e-applications.menu

BUILD_DEFS+=	PKG_SYSCONFBASE

INSTALLATION_DIRS=	${EGDIR}
PKG_SYSCONFSUBDIR=	enlightenment
MAKE_DIRS=		${PKG_SYSCONFDIR}/enlightenment
MAKE_DIRS+=		${PKG_SYSCONFBASE}/xdg/menus

MESON_ARGS+=	-Dsystemd=false
MESON_ARGS+=	-Ddevice-udev=false
MESON_ARGS+=	-Dcpufreq=false
MESON_ARGS+=	-Dsysinfo=false
MESON_ARGS+=	-Dtemperature=false

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fix prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/bin/e_sys_main.c
SUBST_FILES.prefix+=	src/bin/system/e_system_main.c
SUBST_FILES.prefix+=	src/modules/conf_menus/e_int_config_menus.c
SUBST_VARS.prefix=	PREFIX

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CPPFLAGS+=	-DPKGSRC_X11BASE=\"${X11BASE:Q}\"
.endif

.include "../../devel/meson/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../wip/efl/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
