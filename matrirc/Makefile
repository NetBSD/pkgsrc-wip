# $NetBSD$

DISTNAME=	matrirc-1.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=martinetd/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/martinetd/matrirc/
COMMENT=	IRC gateway to matrix 
# TODO: wtfpl should be added to licenses
#LICENSE=	wtfpl

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
