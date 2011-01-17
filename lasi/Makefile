# $NetBSD: Makefile,v 1.3 2011/01/17 10:48:04 emil_s Exp $
#

DISTNAME=	libLASi-1.1.0
PKGNAME=	liblasi-1.1.0
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lasi/}

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://lasi.sourceforge.net/
COMMENT=	C++ library for postscript stream output

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
