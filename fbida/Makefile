# $NetBSD: Makefile,v 1.16 2014/05/31 15:57:19 thomasklausner Exp $
#

DISTNAME=		fbida-2.09
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://www.kraxel.org/releases/fbida/
LICENSE=		gnu-gpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.kraxel.org/blog/linux/fbida/
COMMENT=		Image viewer and editor

MAKE_FILE=		GNUmakefile
MAKE_ENV+=		prefix=${PREFIX}
USE_TOOLS+=		gmake perl

# The jpeg/90 directory doesn't exist yet.
# Populate it ourselves.
post-extract:
	cd ${WRKDIR}/${DISTNAME} && \
	    tar xvzf ${DISTDIR}/jpeg-9c-v2/jpegsrc.v9c.tar.gz && \
	    mkdir jpeg/90 && \
	    for f in jinclude.h jpegint.h jpeglib.h transupp.c transupp.h; \
	    do \
		cp jpeg-9c/$$f jpeg/90; \
	    done

# Depend on this, purely for fetching the distfile.
DEPENDS+=	jpeg>=9c:../../graphics/jpeg

# not used, even though the configure output claims it
#.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/motif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
