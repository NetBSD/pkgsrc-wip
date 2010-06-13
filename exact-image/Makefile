# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:03 thomasklausner Exp $
#

DISTNAME=	exact-image-0.7.5
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://dl.exactcode.de/oss/exact-image/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exactcode.de/site/open_source/exactimage/
COMMENT=	Fast, modern, and generic image processing library

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_TOOLS+=		bash gmake pkg-config
USE_LANGUAGES=		c c++

# Only existing option doesn't build since evas is too new
#.include "options.mk"

post-extract:
	cd ${WRKSRC}/build && ${LN} FreeBSD.make NetBSD.make

.include "../../graphics/agg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
