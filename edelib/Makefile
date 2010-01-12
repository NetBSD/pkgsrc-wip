# $NetBSD: Makefile,v 1.5 2010/01/12 19:15:24 christtrekker Exp $
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
PKG_SUPPORTED_OPTIONS=	dbus fam fam-only largefile nls shared
PKG_SUGGESTED_OPTIONS=	dbus fam nls

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# Solaris /bin/sh is really bad, so use TOOLS_PLATFORM.sh if it's been defined.
.if ${OPSYS} == "SunOS"
REPLACE_SH+=    autogen.sh configure \
                src/tinyscheme/gen-c-string.sh \
                test/abicheck.sh tools/geniconmap
.else
# doxygen doesn't build from pkgsrc on Solaris now - handle this better later
BUILD_DEPENDS+=	doxygen:../../devel/doxygen
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mfam) || !empty(PKG_OPTIONS:Mfam-only)
.  include "../../mk/fam.buildlink3.mk"
.  if !empty(PKG_OPTIONS:Mfam-only)
CONFIGURE_ARGS+=	--enable-fam-only
.  else
CONFIGURE_ARGS+=	--disable-fam-only
.  endif
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

BUILD_DEPENDS+=	jam:../../devel/jam

.include "../../x11/fltk/buildlink3.mk"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} jam
do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} jam install

.include "../../mk/bsd.pkg.mk"
