# $NetBSD: Makefile,v 1.6 2014/05/31 15:57:20 thomasklausner Exp $
#

DISTNAME=	mtpaint-3.50.09
MASTER_SITES=	${MASTER_SITE_GITHUB:=wjaguar/}
GITHUB_TAG=	199472ad6a4ecee6c8583fb5a504a2e99712b4fc
WRKSRC= ${WRKDIR}/mtPaint-${GITHUB_TAG}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mtpaint.sourceforge.net/
COMMENT=	Painting program and photo editor
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	cflags gtk3 jpeg jp2v2 webp intl tiff man
USE_TOOLS+=		gmake pkg-config

BUILD_DEPENDS+=	glib2-[0-9]*:../../devel/glib2
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
