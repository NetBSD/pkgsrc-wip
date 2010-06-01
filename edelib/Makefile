# $NetBSD: Makefile,v 1.6 2010/06/01 19:24:22 christtrekker Exp $
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
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	edelib-dbus.pc.in
PKGCONFIG_OVERRIDE+=	edelib-gui.pc.in
PKGCONFIG_OVERRIDE+=	edelib.pc.in

PKG_OPTIONS_VAR=	PKG_OPTIONS.edelib
PKG_SUPPORTED_OPTIONS=	dbus fam fam-only largefile nls shared
PKG_SUGGESTED_OPTIONS=	dbus fam nls shared
PLIST_VARS+=	shlibs statlibs

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

.include "options.mk"

BUILD_DEPENDS+=	jam:../../devel/jam

.include "../../x11/fltk/buildlink3.mk"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} jam
do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} jam install

.include "../../mk/bsd.pkg.mk"
