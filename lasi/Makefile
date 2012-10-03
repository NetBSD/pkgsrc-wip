# $NetBSD: Makefile,v 1.4 2012/10/03 09:10:35 asau Exp $
#

DISTNAME=	libLASi-1.1.0
PKGNAME=	liblasi-1.1.0
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lasi/}

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://lasi.sourceforge.net/
COMMENT=	C++ library for postscript stream output

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
