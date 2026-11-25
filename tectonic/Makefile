# $NetBSD$

DISTNAME=	tectonic@0.17.0
PKGNAME=	${DISTNAME:S/@/-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tectonic-typesetting/}
GITHUB_PROJECT=	tectonic
GITHUB_TAG=	tectonic@${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tectonic-typesetting.github.io/
COMMENT=	Modernized, complete, self-contained TeX/LaTeX engine
#LICENSE=	mit AND all-kinds-of-other-stuff, see https://github.com/tectonic-typesetting/tectonic?tab=License-1-ov-file

WRKSRC=		${WRKDIR}/tectonic-tectonic-0.17.0
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.harfbuzz}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "cargo-depends.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
