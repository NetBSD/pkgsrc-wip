# $NetBSD: Makefile,v 1.3 2004/02/11 05:24:22 bjan2 Exp $
#

DISTNAME=		simage-1.6.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Library for importing audio and image files

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-ungif --with-jpeg --with-png \
			--with-tiff --with-mpeg2enc
USE_BUILDLINK3=		yes

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
