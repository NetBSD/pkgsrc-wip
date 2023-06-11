# $NetBSD$

DISTNAME=	syncstorage-rs-0.13.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla-services/}
GIT_REPO=	https://github.com/mozilla-services/syncstorage-rs.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla-services/syncstorage-rs/
COMMENT=	Firefox Sync Storage server in Rust
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-FxA-[0-9]*:../../www/py-FxA
DEPENDS+=	${PYPKGPREFIX}-tokenlib-[0-9]*:../../security/py-tokenlib

.include "cargo-depends.mk"

# Depends on an mozilla-modified version of crate
DEADPOOL_REV=				deadpool-v0.5.2-issue92
DISTFILES=				${DEFAULT_DISTFILES}
DISTFILES+=				deadpool-${DEADPOOL_REV}.tar.gz
SITES.deadpool-${DEADPOOL_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=mozilla-services/}deadpool/archive/${DEADPOOL_REV}.tar.gz

USE_LANGUAGES=		c c++ # rust, but needs toolchain
USE_TOOLS+=		pkg-config
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curl}/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

INSTALLATION_DIRS=	bin share/doc/syncstorage-rs share/examples/syncstorage-rs

post-extract:
	mv ${WRKDIR}/deadpool* ${WRKDIR}/deadpool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/syncserver ${DESTDIR}${PREFIX}/bin
	# 'Makefile' has logic how to start this
	${INSTALL_PROGRAM} ${WRKSRC}/Makefile ${DESTDIR}${PREFIX}/share/doc/syncstorage-rs
	${INSTALL_PROGRAM} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/syncstorage-rs
	${INSTALL_PROGRAM} ${WRKSRC}/docs/config.md ${DESTDIR}${PREFIX}/share/doc/syncstorage-rs
	${INSTALL_PROGRAM} ${WRKSRC}/config/local.example.toml ${DESTDIR}${PREFIX}/share/examples/syncstorage-rs

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
