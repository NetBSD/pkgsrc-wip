# $NetBSD: Makefile,v 1.8 2004/08/17 18:32:20 tvierling Exp $

DISTNAME=		simage-1.6.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Library for image format loaders and front-ends

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-ungif --with-jpeg --with-png \
			--with-tiff --with-mpeg2enc
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libsimage.la

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
