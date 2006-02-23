# $NetBSD: Makefile,v 1.1.1.1 2006/02/23 09:42:12 jgoamakf Exp $
#

DISTNAME=	swfmill-0.2.11
CATEGORIES=	graphics converters
MASTER_SITES=	http://iterative.org/swfmill/releases/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://iterative.org/swfmill/
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
