# $NetBSD$

.include "../../wip/signal-desktop/versions.mk"

DISTNAME=		libsignal-node-${LIBSIGNAL_NODE_VER}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=signalapp/}
GITHUB_PROJECT=		libsignal
GITHUB_TAG=		v${PKGVERSION_NOREV}

DISTFILES+=		${DEFAULT_DISTFILES}
DISTFILES+=		boring-signal-v${BORING_SIGNAL_VER}.tar.gz
DISTFILES+=		spqr-v${SPQR_VER}.tar.gz
DISTFILES+=		boringssl-${BORING_HASH}.tar.gz

SITES.boring-signal-v${BORING_SIGNAL_VER}.tar.gz=	-${MASTER_SITE_GITHUB:=signalapp/}boring/archive/signal-v${BORING_SIGNAL_VER}.tar.gz
SITES.spqr-v${SPQR_VER}.tar.gz=				-${MASTER_SITE_GITHUB:=signalapp/}SparsePostQuantumRatchet/archive/v${SPQR_VER}.tar.gz
SITES.boringssl-${BORING_HASH}.tar.gz=			-${MASTER_SITE_GITHUB:=google/}boringssl/archive/${BORING_HASH}.tar.gz

MAINTAINER=		kikadf@NetBSD.org
HOMEPAGE=		https://github.com/signalapp/node-sqlcipher/
COMMENT=		APIs used by the official Signal clients and servers
LICENSE=		gnu-agpl-v3

TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=		clang-[0-9]*:../../lang/clang
USE_LANGUAGES=		c c++

SUBST_CLASSES+=		gh
SUBST_STAGE.gh=		pre-configure
SUBST_MESSAGE.gh=	Set github crates local pathes
SUBST_FILES.gh+=	Cargo.toml
SUBST_VARS.gh+=		SPQR_VER

INSTALLATION_DIRS+=	lib

post-extract:
	${MV} ${WRKDIR}/boring-signal-v${BORING_SIGNAL_VER} ${WRKDIR}/boring-signal
	${RMDIR} ${WRKDIR}/boring-signal/boring-sys/deps/boringssl
	${MV} ${WRKDIR}/boringssl-${BORING_HASH} \
		${WRKDIR}/boring-signal/boring-sys/deps/boringssl

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/release/libsignal_node.so \
		${DESTDIR}${PREFIX}/lib


.include "cargo-depends.mk"

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
CARGO_ARGS+=	-p libsignal-node
CARGO_ARGS+=	--features log/release_max_level_info
.include "../../mk/bsd.pkg.mk"
