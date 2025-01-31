# $NetBSD: Makefile,v 1.12 2012/11/17 10:22:45 kristerw Exp $

DISTNAME=	edelib-2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}

MAINTAINER=	pkgsrc-users@users.sourceforge.net
HOMEPAGE=	https://edeproject.org/
COMMENT=	Libraries for Equinox Desktop
LICENSE=	gnu-lgpl-v2 # or later

USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++11
USE_FEATURES+=		snprintf vsnprintf
USE_TOOLS+=		gsed pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dbus
CONFIGURE_ARGS+=	--disable-rtti
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-largefile

TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
TOOL_DEPENDS+=	jam-[0-9]*:../../devel/jam

.include "../../mk/bsd.prefs.mk"

# Solaris /bin/sh is really bad, so use TOOLS_PLATFORM.sh if it's been defined.
.if ${OPSYS} == "SunOS"
REPLACE_SH+=	autogen.sh configure \
		src/tinyscheme/gen-c-string.sh \
		test/abicheck.sh tools/geniconmap
.endif

REPLACE_PYTHON=	tools/edelib-convert-icontheme tools/edelib-mk-indextheme

CHECK_PORTABILITY_SKIP=	test/run-all.sh

PKGCONFIG_OVERRIDE+=	edelib-dbus.pc.in
PKGCONFIG_OVERRIDE+=	edelib-gui.pc.in
PKGCONFIG_OVERRIDE+=	edelib.pc.in

.include "options.mk"

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} jam -q

do-install:
	cd ${WRKSRC} && env ${INSTALL_ENV} ${MAKE_ENV} jam install

.include "../../lang/python/application.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
