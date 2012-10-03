# $NetBSD: Makefile,v 1.2 2012/10/03 15:09:59 asau Exp $
#

DISTNAME=	mtpaint-3.40
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mtpaint/mtpaint/3.40/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://mtpaint.sourceforge.net/
COMMENT=	Painting program and photo editor
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=		--prefix=${PREFIX} --bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	cflags GIF gtk2 ft jpeg intl tiff man
USE_TOOLS=	gmake

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
