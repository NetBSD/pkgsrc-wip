# $NetBSD$

GITHUB_PROJECT=	Pillow
GITHUB_TAG=	refs/tags/9.0.1
DISTNAME=	9.0.1
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=python-pillow/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-pillow/Pillow/
COMMENT=	Python Imaging Library (PIL)
LICENSE=	hpnd

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../wip/raqm/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
