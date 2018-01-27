# $NetBSD: Makefile,v 1.12 2012/11/17 10:22:45 kristerw Exp $
#

DISTNAME=	edelib-2.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://equinox-project.org/
COMMENT=	Libraries for Equinox Desktop
LICENSE=	gnu-lgpl-v2

CHECK_PORTABILITY_SKIP=	test/run-all.sh

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config jam
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	edelib-dbus.pc.in
PKGCONFIG_OVERRIDE+=	edelib-gui.pc.in
PKGCONFIG_OVERRIDE+=	edelib.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.edelib
PKG_SUPPORTED_OPTIONS=	largefile nls shared
PKG_SUGGESTED_OPTIONS=	nls shared
PLIST_VARS+=		shlibs statlibs

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# Solaris /bin/sh is really bad, so use TOOLS_PLATFORM.sh if it's been defined.
.if ${OPSYS} == "SunOS"
REPLACE_SH+=	autogen.sh configure \
                src/tinyscheme/gen-c-string.sh \
                test/abicheck.sh tools/geniconmap
.else
# doxygen doesn't build from pkgsrc on Solaris now - handle this better later
BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
.endif

.include "options.mk"

BUILD_DEPENDS+=	jam-[0-9]*:../../devel/jam

.include "../../mk/fam.buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} jam
do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} jam install

.include "../../mk/bsd.pkg.mk"
