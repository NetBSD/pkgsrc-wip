# $NetBSD$

DISTNAME=	spotifyd-0.3.3
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Spotifyd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	https://github.com/Spotifyd/spotifyd/
COMMENT=	Open source Spotify client running as a UNIX daemon
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

USE_LANGUAGES=	c # rust, but needs a toolchain to link
USE_TOOLS+=	pkg-config

DISTFILES=	${DEFAULT_DISTFILES}

# work around weird version pattern not supported by cargo.mk
SITES.wasi-0.9.0+wasi-snapshot-preview1.crate+=	-https://crates.io/api/v1/crates/wasi/0.9.0+wasi-snapshot-preview1/download

INSTALLATION_DIRS+=	bin

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

CARGO_NO_DEFAULT_FEATURES=	YES

#  NOTE: To update this package currently you need to something like this:
#  1. Update version in makefile
#  2. `make clean`
#  3. `make fetch`
#  4. `make mdi`
#  5. `make extract`
#  6. Update the cargo crate depends list, `make show-cargo-depends > cargo-depends.mk`
#  7. `make clean`
#  8. `make fetch`
#  9. `make mdi`
#  10. `make extract`
#  11. `make patch`
#  12. That might fail. Need to update patches, etc with help of `pkgvi` and `pkgdiff`, e.g: `pkgdiff Cargo.lock.orig Cargo.lock > ../../patches/patch-Cargo.lock`, etc
#  13. If patches updated `make mdi`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/spotifyd ${DESTDIR}${PREFIX}/bin

.include "options.mk"

BUILDLINK_API_DEPENDS.rust+=   rust>=1.40.0
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
