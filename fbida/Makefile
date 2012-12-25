# $NetBSD: Makefile,v 1.14 2012/12/25 18:19:27 noud4 Exp $
#

DISTNAME=		fbida-2.08
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://www.kraxel.org/releases/fbida/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.kraxel.org/blog/linux/fbida/
COMMENT=		Image viewer and editor

MAKE_FILE=		GNUmakefile
MAKE_ENV+=		prefix=${PREFIX:Q}
USE_TOOLS+=		gmake perl

# not used, even though the configure output claims it
#.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/motif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
