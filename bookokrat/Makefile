# $NetBSD$

DISTNAME=	bookokrat-0.3.11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=bugzmanov/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bugzmanov/bookokrat
COMMENT=	Terminal based epub reader
LICENSE=	gnu-agpl-v3

RUST_REQ=	1.86
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES+=	c c++

RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/${BUILDLINK_LIBDIRS.fontconfig}

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
