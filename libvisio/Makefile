# $NetBSD: Makefile,v 1.1.1.1 2012/03/03 10:47:42 ftigeot Exp $

VER=		0.0.15
DISTNAME=	libvisio-${VER}
PKGNAME=	libvisio-${VER:S/-//g}
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/libvisio/
COMMENT=	Library and tools for parsing the visio file format
LICENSE=	gnu-lgpl-v2.1
#LICENSE+=	mpl-1.1
#LICENSE+=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
