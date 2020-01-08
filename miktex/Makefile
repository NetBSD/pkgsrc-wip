# $NetBSD$

DISTNAME=	miktex-2.9.7250
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	https://miktex.org/download/ctan/systems/win32/miktex/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://miktex.org/download/ctan/systems/win32/miktex/source/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	bison pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

BUILD_DEPENDS+=	log4cxx-[0-9]*:../../devel/log4cxx
# or lzmalib?
BUILD_DEPENDS+=	lzma-[0-9]*:../../archivers/lzma

.include "options.mk"

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
# \todo? harfbuzz-icu
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../archivers/libmspack/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
# and poppler-cpp?
.include "../../print/poppler/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/potrace/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
