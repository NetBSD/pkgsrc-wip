# $NetBSD$

DISTNAME=	pijul-1.0.0-beta.2
CATEGORIES=	devel
MASTER_SITES=	https://static.crates.io/crates/pijul/
DISTFILES=	pijul-1.0.0-beta.2.crate

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://pijul.org/
COMMENT=	Distributed version control system
LICENSE=	gnu-gpl-v2

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
MAKE_ENV+=		DEP_SODIUM_INCLUDE=${BUILDLINK_PREFIX.libsodium}/include
MAKE_ENV+=		DEP_SODIUM_LIB=${BUILDLINK_PREFIX.libsodium}/lib
# \TODO: Not picked up, but DEP_SODIUM_ is picked up, why?
#MAKE_ENV+=		SODIUM_LIB_DIR=${BUILDLINK_PREFIX.libsodium:Q}
RUSTFLAGS+=             -C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.zstd}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.xxhash}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pijul ${DESTDIR}${PREFIX}/bin

.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
