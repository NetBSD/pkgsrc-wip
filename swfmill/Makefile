# $NetBSD: Makefile,v 1.5 2014/04/12 17:54:47 thomasklausner Exp $

DISTNAME=	swfmill-0.3.3
CATEGORIES=	graphics converters
MASTER_SITES=	http://swfmill.org/releases/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://swfmill.org/
COMMENT=	Collection of SWF manipulation and creation utilities
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
