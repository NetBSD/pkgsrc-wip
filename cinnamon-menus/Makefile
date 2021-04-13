# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	cinnamon-menus-4.6.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=linuxmint/}
GITHUB_PROJECT=	cinnamon-menus
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cinnamon-menus
COMMENT=	Additional UI API for cinnamon
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool
#USE_TOOLS+=	pkg-config automake autoreconf intltool msgfmt
#GNU_CONFIGURE=	yes

#PKGCONFIG_OVERRIDE+=	libmenu/libcinnamon-menu-3.0.pc.in

#BUILD_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive

#pre-configure:
#	cd ${WRKSRC} && NOCONFIGURE=1 ./autogen.sh

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
