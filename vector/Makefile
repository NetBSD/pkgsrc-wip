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

.include "cargo-depends.mk"

RUST_REQ=	1.88.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config perl gmake

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.LuaJIT2}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.LuaJIT2}/lib
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
