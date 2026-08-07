# $NetBSD$

DISTNAME=	icann-rdap-0.0.30
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=icann/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/icann/icann-rdap/
COMMENT=	ICANN RDAP client + server
LICENSE=	apache-2.0 OR mit

PKG_OPTIONS_VAR=		PKG_OPTIONS.icann-rdap
PKG_SUPPORTED_OPTIONS=		client server test
PKG_SUGGESTED_OPTIONS=		client server test

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	client server test

# rdap and rdap-test are both built from the icann-rdap-cli crate, so they
# share a single -p invocation; only the --bin selection differs.
.if !empty(PKG_OPTIONS:Mclient) || !empty(PKG_OPTIONS:Mtest)
CARGO_BUILD_FLAGS+=	-p icann-rdap-cli
.  if !empty(PKG_OPTIONS:Mclient)
PLIST.client=		yes
CARGO_BUILD_FLAGS+=	--bin rdap
.  endif
.  if !empty(PKG_OPTIONS:Mtest)
PLIST.test=		yes
CARGO_BUILD_FLAGS+=	--bin rdap-test
.  endif
.endif

# rdap-srv, rdap-srv-data, rdap-srv-store, and rdap-srv-test-data all come
# from the icann-rdap-srv crate, which pulls in axum/sqlx/tower/hyper --
# skip it entirely to avoid that dependency tree when the server isn't
# wanted.
.if !empty(PKG_OPTIONS:Mserver)
PLIST.server=		yes
CARGO_BUILD_FLAGS+=	-p icann-rdap-srv
RCD_SCRIPTS+=		rdap-srv
.endif

PKG_RCD_SCRIPTS=	no

# Crates whose version string embeds a hyphen after the "+" build-metadata
# separator confuse pkgsrc's crate-name/version auto-split, so their
# download URL needs to be given explicitly.
SITES.wasi-0.11.1+wasi-snapshot-preview1.crate=	https://static.crates.io/crates/wasi/
SITES.wasip2-1.0.4+wasi-0.2.12.crate=			https://static.crates.io/crates/wasip2/
SITES.toml_datetime-1.1.1+spec-1.1.0.crate=		https://static.crates.io/crates/toml_datetime/
SITES.toml_edit-0.25.12+spec-1.1.0.crate=		https://static.crates.io/crates/toml_edit/
SITES.toml_parser-1.1.2+spec-1.1.0.crate=		https://static.crates.io/crates/toml_parser/

.include "cargo-depends.mk"

#RUST_REQ=	1.85.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.85.1 on amd64
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

INSTALLATION_DIRS=	bin

do-install:
.if !empty(PKG_OPTIONS:Mclient)
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap \
		${DESTDIR}${PREFIX}/bin
.endif
.if !empty(PKG_OPTIONS:Mtest)
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap-test \
		${DESTDIR}${PREFIX}/bin
.endif
.if !empty(PKG_OPTIONS:Mserver)
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap-srv \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap-srv-data \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap-srv-store \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rdap-srv-test-data \
		${DESTDIR}${PREFIX}/bin
.endif

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
