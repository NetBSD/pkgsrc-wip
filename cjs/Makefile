# $NetBSD$
# $NetBSD$: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	cjs-5.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	cjs
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cjs
COMMENT=	Javascript bindings based on gobject-introspection
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake cmake bash pkg-config autoreconf automake intltool
CONFIG_SHELL=	bash
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-profiler

TOOL_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive

.include "../../devel/meson/build.mk"
.include "../../lang/mozjs78/buildlink3.mk"
.include "../../lang/spidermonkey185/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
