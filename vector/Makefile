# $NetBSD$

DISTNAME=	vector-0.50.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=vectordotdev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vector.dev/
COMMENT=	High-performance observability data pipeline
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
#TOOL_DEPENDS+=	cargo-nextest-[0-9]*:../../wip/cargo-nextest
#TOOL_DEPENDS+=	cargo-auditable-[0-9]*:../../wip/cargo-auditable

.include "cargo-depends.mk"

# Depends on an unpublished crates. Can't use cargo.mk to fetch it.
NTAPI_REV=			24fc1e47677fc9f6e38e5f154e6011dc9b270da6
NIX_REV=			6c53a918d2d5bf4307fd60a19d9e10913ae71eeb
TOKIO-UTIL_REV=			b4bdfda8fe8aa24eba36de0d60063b14f30c7fe7
VRL_REV=			560dac8b6b494d722fa9a57d98ed2e7e36ee75f6
TRACING-TOWER_REV=		e0642d949891546a3bb7e47080365ee7274f05cd
GREPTIMEDB-INGESTER_REV=	f7243393808640f5123b0d5b7b798da591a4df6e
HEIM_REV=			f3537d9b32e69a2a8ab19a0d42a1e6f5577a5a45
TRACING-FUTURES_REV=		e0642d949891546a3bb7e47080365ee7274f05cd
TRACING-CORE_REV=		e0642d949891546a3bb7e47080365ee7274f05cd
TRACING_REV=			e0642d949891546a3bb7e47080365ee7274f05cd
GREPTIME-PROTO_REV=		396206c2801b5a3ec51bfe8984c66b686da910e6

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	ntapi-${NTAPI_REV}.tar.gz
DISTFILES+=	nix-${NIX_REV}.tar.gz
DISTFILES+=	tokio-util-${TOKIO-UTIL_REV}.tar.gz
DISTFILES+=	vrl-${VRL_REV}.tar.gz
DISTFILES+=	tracing-tower-${TRACING-TOWER_REV}.tar.gz
DISTFILES+=	greptimedb-ingester-${GREPTIMEDB-INGESTER_REV}.tar.gz
DISTFILES+=	heim-${HEIM_REV}.tar.gz
DISTFILES+=	tracing-futures-${TRACING-FUTURES_REV}.tar.gz
DISTFILES+=	tracing-core-${TRACING-CORE_REV}.tar.gz
DISTFILES+=	tracing-${TRACING_REV}.tar.gz
DISTFILES+=	greptime-proto-${GREPTIME-PROTO_REV}.tar.gz

SITES.ntapi-${NTAPI_REV}.tar.gz=				-${MASTER_SITE_GITHUB:=MSxDOS/}ntapi/archive/${NTAPI_REV}.tar.gz
SITES.nix-${NIX_REV}.tar.gz=					-${MASTER_SITE_GITHUB:=vectordotdev/}nix/archive/${NIX_REV}.tar.gz
SITES.tokio-util-${TOKIO-UTIL_REV}.tar.gz=			-${MASTER_SITE_GITHUB:=vectordotdev/}tokio/archive/${TOKIO-UTIL_REV}.tar.gz
SITES.vrl-${VRL_REV}.tar.gz=					-${MASTER_SITE_GITHUB:=vectordotdev/}vrl/archive/${VRL_REV}.tar.gz
SITES.tracing-tower-${TRACING-TOWER_REV}.tar.gz=		-${MASTER_SITE_GITHUB:=tokio-rs/}tracing/archive/${TRACING-TOWER_REV}.tar.gz
SITES.greptimedb-ingester-${GREPTIMEDB-INGESTER_REV}.tar.gz=	-${MASTER_SITE_GITHUB:=GreptimeTeam/}greptimedb-ingester-rust/archive/${GREPTIMEDB-INGESTER_REV}.tar.gz
SITES.heim-${HEIM_REV}.tar.gz=					-${MASTER_SITE_GITHUB:=vectordotdev/}heim/archive/${HEIM_REV}.tar.gz
SITES.tracing-futures-${TRACING-FUTURES_REV}.tar.gz=		-${MASTER_SITE_GITHUB:=tokio-rs/}tracing/archive/${TRACING-FUTURES_REV}.tar.gz
SITES.tracing-core-${TRACING-CORE_REV}.tar.gz=			-${MASTER_SITE_GITHUB:=tokio-rs/}tracing/archive/${TRACING-CORE_REV}.tar.gz
SITES.tracing-${TRACING_REV}.tar.gz=				-${MASTER_SITE_GITHUB:=tokio-rs/}tracing/archive/${TRACING_REV}.tar.gz
SITES.greptime-proto-${GREPTIME-PROTO_REV}.tar.gz=		-${MASTER_SITE_GITHUB:=GreptimeTeam/}greptime-proto/archive/${GREPTIME-PROTO_REV}.tar.gz

RUST_REQ=	1.88.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=		OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.LuaJIT2}/lib
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.LuaJIT2}/lib
#INSTALLATION_DIRS+=	bin
#
#do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sg \
#		${DESTDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ast-grep \
#		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
#.include "../../lang/lua54/buildlink3.mk"
#.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
