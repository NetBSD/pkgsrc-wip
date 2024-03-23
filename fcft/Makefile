# $NetBSD$

DISTNAME=	fcft-3.1.8
CATEGORIES=	fonts
MASTER_SITES=	https://codeberg.org/dnkl/fcft/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://codeberg.org/dnkl/fcft/
COMMENT=	Simple library for font loading and glyph rasterization
LICENSE=	mit

USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

.include "../../converters/utf8proc/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../wip/tllist/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
