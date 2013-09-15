# $NetBSD: Makefile,v 1.3 2013/09/15 17:22:37 roelants Exp $
#

DISTNAME=	evas_generic_loaders-1.7.8
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	Extra loaders for GPL loaders and unstable libraries

LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../wip/eina/buildlink3.mk" # devel
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
