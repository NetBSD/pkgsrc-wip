# $NetBSD$

DISTNAME=	c2rust-0.20.0.20250630
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=immunant/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	82acf86dda1fc80e8292e1fa035937ff6403d526

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c2rust.com/
COMMENT=	Translate C modules into semantically equivalent Rust code
LICENSE=	modified-bsd

# c2rust-ast-exporter
TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake
# TODO: c2rust-ast-exporter clones tinycbor - don't do that
ALLOW_NETWORK_ACCESS=	yes
USE_TOOLS+=		git
# tinycbor again
USE_TOOLS+=		gmake

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

.include "../../lang/rust/cargo.mk"
# tinycbor, again
.include "../../lang/llvm/buildlink3.mk"
# tinycbor, again
.include "../../lang/clang/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
