# $NetBSD: Makefile,v 1.13 2012/09/28 23:21:47 asau Exp $
#

DISTNAME=		fbida-2.08
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
.include "../../x11/openmotif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
