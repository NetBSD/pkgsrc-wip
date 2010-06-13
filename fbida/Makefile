# $NetBSD: Makefile,v 1.8 2010/06/13 22:47:03 thomasklausner Exp $
#

DISTNAME=		fbida-2.03
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		http://dl.bytesex.org/releases/fbida/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://linux.bytesex.org/fbida/
COMMENT=		Image viewer and editor

MAKE_FILE=		GNUmakefile
MAKE_ENV+=		prefix=${PREFIX:Q}
USE_TOOLS+=		gmake perl

# not used, even though the configure output claims it
#.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
#.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/openmotif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
