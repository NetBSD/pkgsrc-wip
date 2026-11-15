# $NetBSD$

.include "versions.mk"

DISTNAME=		signal-desktop-${SIGNAL_VERSION}
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=signalapp/}
GITHUB_PROJECT=		Signal-Desktop
GITHUB_TAG=		v${PKGVERSION_NOREV}

NODE_MODULES=		signal-desktop-node_modules-${PKGVERSION_NOREV}.tar.gz
#MASTER_SITES+=		https://distfiles.borderland.hu/
DISTFILES+=		${NODE_MODULES}
DISTFILES+=		${DEFAULT_DISTFILES}

# lightningcss
GITHUB_SUBMODULES+=	parcel-bundler lightningcss v${LIGHTNINGCSS_VER} lightningcss
LIGHTNINGCSS_DIR=	${WRKSRC}/node_modules/.pnpm/lightningcss@${LIGHTNINGCSS_VER}/node_modules/lightningcss
CARGO_WRKSRC=		${WRKSRC}/lightningcss
.include "cargo-depends.mk"

MAINTAINER=		kikadf@NetBSD.org
HOMEPAGE=		https://signal.org/
COMMENT=		Cross-platform centralized encrypted messaging service
LICENSE=		gnu-agpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

TOOL_DEPENDS+=		ringrtc>=${RINGRTC_VER}:../../wip/ringrtc
TOOL_DEPENDS+=		libsignal-node>=${LIBSIGNAL_NODE_VER}:../../wip/libsignal-node
TOOL_DEPENDS+=		node-sqlcipher>=${SQLCIPHER_VER}:../../wip/node-sqlcipher
TOOL_DEPENDS+=		pnpm-[0-9]*:../../wip/pnpm

.include "../../wip/electron${ELECTRON_MAJOR_VER}/electron.mk"

SIGNAL_ARCH=		${MACHINE_ARCH:S/aarch64/arm64/:S/x86_64/x64/}
BUILD_EPOCH=		date +'%s'

MAKE_ENV+=		ELECTRON_SKIP_BINARY_DOWNLOAD=1
MAKE_ENV+=		ELECTRON_OVERRIDE_DIST_PATH=${PREFIX}/lib/electron${ELECTRON_MAJOR_VER}
MAKE_ENV+=		NODE_OPTIONS="--max-old-space-size=8192"
MAKE_ENV+=		PYTHONDONTWRITEBYTECODE=1
MAKE_ENV+=		JOBS=${_MAKE_JOBS_N}
MAKE_ENV+=		SOURCE_DATE_EPOCH=${BUILD_EPOCH:sh}

PNPM_ENV=		npm_config_nodedir=${PREFIX}/lib/electron${ELECTRON_MAJOR_VER}/node_headers
PNPM_ENV+=		pnpm_config_runtime_on_fail=ignore
PNPM_ENV+=		pnpm_config_trust_lockfile=true
PNPM_ENV+=		pnpm_config_verify_deps_before_run=false
PNPM_ENV+=		pnpm_config_pm_on_fail=ignore

PREPEND_PATH+=		${NODE_GYP_PATH}

CFLAGS+=		-I${PREFIX}/include/node
#CXXFLAGS+=		-std=c++20

PNPM_FLAGS=		--pm-on-fail=ignore --offline --trust-lockfile
PNPM_FLAGS+=		--store-dir=${WRKDIR}/signal-desktop-node_modules-${PKGVERSION_NOREV}

NOT_PAX_MPROTECT_SAFE+=	lib/signal-desktop/signal-desktop

UNLIMIT_RESOURCES+=	datasize virtualsize

.if defined(SIGNAL_MAINTAINER)
# For create npm cache tarball
USE_TOOLS+=		bsdtar

MPNPM_FLAGS=		--pm-on-fail=ignore --ignore-scripts
MPNPM_FLAGS+=		--store-dir=${WRKDIR}/signal-desktop-tmp/signal-desktop-node_modules-${PKGVERSION_NOREV}

.PHONY: cache-tarball
cache-tarball:
	${MKDIR} ${WRKDIR}/signal-desktop-tmp/signal-desktop-node_modules-${PKGVERSION_NOREV}
	${TOOLS_PATH.bsdtar} -zxf ${DISTDIR}/${DISTNAME}.tar.gz \
		--strip-components=1 -C ${WRKDIR}/signal-desktop-tmp
	cd ${WRKDIR}/signal-desktop-tmp && \
		printf 'supportedArchitectures:\n  os: [current]\n  cpu: [current, wasm32]\n' \
		>> pnpm-workspace.yaml && \
		pnpm ${MPNPM_FLAGS} fetch
	cd ${WRKDIR}/signal-desktop-tmp && \
		${TOOLS_PATH.bsdtar} -czf ${WRKDIR}/signal-desktop-node_modules-${PKGVERSION_NOREV}.tar.gz \
		signal-desktop-node_modules-${PKGVERSION_NOREV}
.endif

post-extract:
	cd ${WRKSRC} && \
		printf 'supportedArchitectures:\n  os: [current]\n  cpu: [current, wasm32]\n' \
		>> pnpm-workspace.yaml && \
		${SETENV} ${MAKE_ENV} ${PNPM_ENV} pnpm install --ignore-scripts ${PNPM_FLAGS}

do-configure:
	# Install libsignal_node.so, and node_sqlcipher.node binaries in node_modules
	${MKDIR} ${WRKSRC}/node_modules/@signalapp/libsignal-client/prebuilds/${LOWER_OPSYS}-${SIGNAL_ARCH}
	${MKDIR} ${WRKSRC}/node_modules/@signalapp/sqlcipher/prebuilds/${LOWER_OPSYS}-${SIGNAL_ARCH}
	${CP} ${PREFIX}/lib/libsignal_node.so \
		${WRKSRC}/node_modules/@signalapp/libsignal-client/prebuilds/${LOWER_OPSYS}-${SIGNAL_ARCH}/@signalapp+libsignal-client.node
	${CP} ${PREFIX}/lib/node_sqlcipher.node \
		${WRKSRC}/node_modules/@signalapp/sqlcipher/prebuilds/${LOWER_OPSYS}-${SIGNAL_ARCH}

	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PNPM_ENV} pnpm install ${PNPM_FLAGS}

	# Install libringrtc.so binaries in node_modules
	${MKDIR} ${WRKSRC}/node_modules/@signalapp/ringrtc/build/${LOWER_OPSYS}
	${CP} ${PREFIX}/lib/libringrtc.so \
		${WRKSRC}/node_modules/@signalapp/ringrtc/build/${LOWER_OPSYS}/libringrtc-${SIGNAL_ARCH}.node


	cd ${WRKSRC}/node_modules/.pnpm/@parcel+watcher@*/node_modules/@parcel/watcher && \
		${SETENV} ${MAKE_ENV} ${PNPM_ENV} ${NODE_GYP} rebuild -j ${_MAKE_JOBS_N}

do-build: do-cargo-build
	# Copy lightningcss native module
	${CP} ${WRKSRC}/lightningcss/target/release/liblightningcss_node.so \
		${LIGHTNINGCSS_DIR}/lightningcss.${LOWER_OPSYS}-${SIGNAL_ARCH}.node

	cd ${WRKSRC}/sticker-creator && \
		${SETENV} ${MAKE_ENV} ${PNPM_ENV} pnpm run build
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PNPM_ENV} pnpm run build

BUILDDIR=		${WRKDIR}/Signal-Desktop-${ELECTRON_ARCH}
INSTALLATION_DIRS+=	lib/signal-desktop
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

do-install:


.include "../../lang/nodejs/nodeversion.mk"
.include "../../lang/nodejs/application.mk"
.include "../../lang/rust/cargo.mk"
CARGO_ARGS+=	-p lightningcss_node
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
