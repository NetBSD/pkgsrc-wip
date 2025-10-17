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
TOOL_DEPENDS+=	cargo-nextest-[0-9]*:../../wip/cargo-nextest
TOOL_DEPENDS+=	cargo-auditable-[0-9]*:../../wip/cargo-auditable

GITHUB_SUBMODULES+=	MSxDOS ntapi 24fc1e47677fc9f6e38e5f154e6011dc9b270da6 ntapi
GITHUB_SUBMODULES+=	vectordotdev nix 6c53a918d2d5bf4307fd60a19d9e10913ae71eeb memfd/gnu/musl
GITHUB_SUBMODULES+=	vectordotdev tokio b4bdfda8fe8aa24eba36de0d60063b14f30c7fe7 tokio-util-0.7.13-framed-read-continue-on-error

.include "cargo-depends.mk"

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
.include "../../lang/lua54/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
