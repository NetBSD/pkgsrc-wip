# $NetBSD: Makefile,v 1.1.1.1 2004/02/10 20:42:21 bjan2 Exp $
#

DISTNAME=		simage-1.6.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://www.coin3d.org
COMMENT=		Library for importing audio and image files

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-ungif --with-jpeg --with-png \
			--with-tiff --with-mpeg2enc
USE_BUILDLINK2=		yes

.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
