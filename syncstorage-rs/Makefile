# $NetBSD: Makefile,v 1.10 2024/11/01 12:54:57 wiz Exp $

DISTNAME=	syncstorage-rs-0.17.15
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mozilla-services/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla-services/syncstorage-rs/
COMMENT=	Firefox Sync Storage server in Rust
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-FxA-[0-9]*:../../www/py-FxA
DEPENDS+=	${PYPKGPREFIX}-tokenlib-[0-9]*:../../security/py-tokenlib
# for tokenserver tools
# not needed in most installations, see
# https://github.com/mozilla-services/syncstorage-rs/issues/1569
#DEPENDS+=	${PYPKGPREFIX}-boto>=2.49.0:../../net/py-boto
#DEPENDS+=	${PYPKGPREFIX}-hawkauthlib>=2.0.0:../../security/py-hawkauthlib
#DEPENDS+=	${PYPKGPREFIX}-mysqlclient>=2.1.1:../../databases/py-mysqlclient
#DEPENDS+=	${PYPKGPREFIX}-pyramid>=2.0.1:../../wip/py-pyramid
#DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.4.46:../../databases/py-sqlalchemy
#DEPENDS+=	${PYPKGPREFIX}-testfixtures>=0:../../wip/py-testfixtures
#DEPENDS+=	${PYPKGPREFIX}-tokenlib>=2.0.0:../../security/py-tokenlib
#DEPENDS+=	${PYPKGPREFIX}-BrowserID>=0.14.0:../../www/py-BrowserID

#CARGO_ARGS+=	build --release ${DEFAULT_CARGO_ARGS} --no-default-features --features=syncstorage-db/mysql,tokenserver-auth/py

RUST_REQ+=	1.80

# https://github.com/mozilla-services/syncstorage-rs/issues/1617
PYTHON_VERSIONS_INCOMPATIBLE=	313

.include "cargo-depends.mk"

SITES.curl-sys-0.4.78+curl-8.11.0.crate=	https://static.crates.io/crates/curl-sys/

# needs snapshot
SENTRY_REV=					1b65b5c99af975496880e7325218479e0037d097
DISTFILES=					${DEFAULT_DISTFILES}
DISTFILES+=					sentry-rust-${SENTRY_REV}.tar.gz
SITES.sentry-rust-${SENTRY_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=getsentry/}sentry-rust/archive/${SENTRY_REV}.tar.gz

USE_LANGUAGES=		c c++ # rust, but needs toolchain
USE_TOOLS+=		pkg-config
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.curl}/lib

INSTALLATION_DIRS+=	bin share/doc/syncstorage-rs share/examples/syncstorage-rs
INSTALLATION_DIRS+=	lib/tokenserver

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/syncserver ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/syncstorage-rs
	${INSTALL_DATA} ${FILESDIR}/setup.md ${DESTDIR}${PREFIX}/share/doc/syncstorage-rs
	${INSTALL_DATA} ${WRKSRC}/docs/config.md ${DESTDIR}${PREFIX}/share/doc/syncstorage-rs
	${INSTALL_DATA} ${WRKSRC}/config/local.example.toml ${DESTDIR}${PREFIX}/share/examples/syncstorage-rs
#	${INSTALL_SCRIPT} ${WRKSRC}/tools/tokenserver/*.* ${DESTDIR}${PREFIX}/lib/tokenserver

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
