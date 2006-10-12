# $NetBSD: Makefile,v 1.2 2006/10/12 21:13:42 shattered Exp $
#

DISTNAME=	swfmill-0.2.11
CATEGORIES=	graphics converters
MASTER_SITES=	http://swfmill.org/releases/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://swfmill.org/
COMMENT=	Collection of SWF manipulation and creation utilities

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
