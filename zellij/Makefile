# $NetBSD$

DISTNAME=	zellij-0.39.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=zellij-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zellij.dev/
COMMENT=	Terminal workspace with batteries included
LICENSE=	mit

# wasmer only supports 64bits systems.
# https://github.com/wasmerio/wasmer/issues/4244#issuecomment-1751365804
ONLY_FOR_PLATFORM=      ${LP64PLATFORMS}

.include "cargo-depends.mk"

SITES.curl-sys-0.4.68+curl-8.4.0.crate=	https://static.crates.io/crates/curl-sys/

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config gmake perl

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

post-patch:
	${CP} ${FILESDIR}/netbsd.rs ${WRKDIR}/vendor/region-3.0.0/src/os/

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
