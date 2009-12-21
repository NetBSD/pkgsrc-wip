# $NetBSD: Makefile,v 1.4 2009/12/21 19:25:39 christtrekker Exp $
#

DISTNAME=	edelib-2.0-beta
PKGNAME=	${DISTNAME:S/-beta//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://equinox-project.org/
COMMENT=	Libraries for Equinox Desktop
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/edelib-2.0-beta
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config jam
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	edelib-dbus.pc.in
PKGCONFIG_OVERRIDE+=	edelib-gui.pc.in
PKGCONFIG_OVERRIDE+=	edelib.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.edelib
PKG_SUPPORTED_OPTIONS=	dbus fam-only largefile nls shared
PKG_SUGGESTED_OPTIONS=	dbus nls

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

BUILD_DEPENDS+=	jam:../../devel/jam
BUILD_DEPENDS+=	doxygen:../../devel/doxygen

.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mfam-only)
CONFIGURE_ARGS+=	--enable-fam-only
.else
CONFIGURE_ARGS+=	--disable-fam-only
.endif

.if !empty(PKG_OPTIONS:Mlargefile)
CONFIGURE_ARGS+=	--enable-largefile
.else
CONFIGURE_ARGS+=	--disable-largefile
.endif

.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mshared)
CONFIGURE_ARGS+=	--enable-shared
.else
CONFIGURE_ARGS+=	--disable-shared
.endif

.include "../../mk/fam.buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

do-build:
	cd ${WRKSRC} && jam
do-install:
	cd ${WRKSRC} && jam install

.include "../../mk/bsd.pkg.mk"
