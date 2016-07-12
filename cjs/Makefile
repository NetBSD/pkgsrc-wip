# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	3.0.1
PKGNAME=	cjs-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=/linuxmint/cjs/archive/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/linuxmint/cjs
COMMENT=	Javascript bindings based on gobject-introspection
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake bash pkg-config automake intltool
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libmenu/libcinnamon-menu-3.0.pc.in

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

BUILD_DEPENDS+=	gnome-common-[0-9]*:../../devel/gnome-common

.include "../../wip/spidermonkey24/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
