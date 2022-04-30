# $NetBSD$

DISTNAME=	syncstorage-rs-0.11.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla-services/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla-services/syncstorage-rs/
COMMENT=	Firefox Sync Storage server in Rust
LICENSE=	mpl-2.0

BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

# Depends on an mozilla-modified version of crate
DEADPOOL_REV=				deadpool-v0.5.2-issue92
DISTFILES=				${DEFAULT_DISTFILES}
DISTFILES+=				deadpool-${DEADPOOL_REV}.tar.gz
SITES.deadpool-${DEADPOOL_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=mozilla-services/}deadpool/archive/${DEADPOOL_REV}.tar.gz

# automatic download path generation doesn't work for this crate
CURL_SYS_REV=				0.4.52+curl-7.81.0
SITES.curl-sys-${CURL_SYS_REV}.crate+=	-${MASTER_SITE_CRATESIO}curl-sys/0.4.52+curl-7.81.0/download

USE_LANGUAGES=		c c++ # rust, but needs toolchain
USE_TOOLS+=		pkg-config
#RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.abseil}/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	mv ${WRKDIR}/deadpool* ${WRKDIR}/deadpool

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
#.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/tool.mk"
#.include "../../net/grpc/buildlink3.mk"
#.include "../../devel/abseil/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
