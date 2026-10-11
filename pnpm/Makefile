# $NetBSD$

PKGNAME=	${DISTNAME:C/-rc\./rc/}
DISTNAME=	pnpm-12.12.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pnpm/}
GITHUB_TAG=	refs/tags/v${DISTNAME:C/^[^-]*-//}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://pnpm.io/
COMMENT=	Fast, disk space efficient package manager
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	esbuild>=0.28:../../wip/esbuild

RUST_REQ=	1.98

INSTALLATION_DIRS=	bin

CARGO_ARGS=		build --release --bin pnpm ${DEFAULT_CARGO_ARGS}

# Depends on unpublished crates. Can't use cargo.mk to fetch them.
NODE_SEMVER_REV=	3d74d6b7f4de1de2006cf2f7663aac09de65b1f6
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		node-semver-${NODE_SEMVER_REV}.tar.gz

SITES.node-semver-${NODE_SEMVER_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=pnpm/}node-semver-rs/archive/${NODE_SEMVER_REV}.tar.gz

# Required to generate cas-loader.mjs.inc.
ENHANCED_RESOLVE_VER=	5.26.0
# TODO: This version is not same as what pnpm uses. pnpm uses patched version.
GRACEFUL_FS_VER=	4.2.11
TAPABLE_VER=		2.3.3
DISTFILES+=		enhanced-resolve-${ENHANCED_RESOLVE_VER}.tgz
DISTFILES+=		graceful-fs-${GRACEFUL_FS_VER}.tgz
DISTFILES+=		tapable-${TAPABLE_VER}.tgz

SITES.enhanced-resolve-${ENHANCED_RESOLVE_VER}.tgz+=	https://registry.npmjs.org/enhanced-resolve/-/
SITES.graceful-fs-${GRACEFUL_FS_VER}.tgz+=		https://registry.npmjs.org/graceful-fs/-/
SITES.tapable-${TAPABLE_VER}.tgz+=			https://registry.npmjs.org/tapable/-/

EXTRACT_DIR.enhanced-resolve-${ENHANCED_RESOLVE_VER}.tgz+=	${WRKDIR}/enhanced-resolve
EXTRACT_DIR.graceful-fs-${GRACEFUL_FS_VER}.tgz+=		${WRKDIR}/graceful-fs
EXTRACT_DIR.tapable-${TAPABLE_VER}.tgz+=			${WRKDIR}/tapable

post-extract:
	@${STEP_MSG} "Relocating cargo crates in the pnpm way ;)"
	${RUN}${MKDIR} ${WRKSRC}/.pnpm/crates/git
	${RUN}${MV} ${WRKDIR}/node-semver-rs-${NODE_SEMVER_REV} ${WRKSRC}/.pnpm/crates/git/node-semver
	${RUN}${SED} "s/@NODE_SEMVER_REV@/${NODE_SEMVER_REV}/" ${FILESDIR}/config.toml > ${WRKSRC}/.pnpm/crates/config.toml

#	NOTE: cargo-checksum.json was generated as follows.
#		${FIND} . -type f ! -name .cargo-checksum.json -print0 | xargs -0 ${DIGEST} sha256 | ${AWK} \
#		'BEGIN { first=1; printf "{\"files\":{" } \
#		 /^SHA256 / { if (first==0) { printf "," } else { first=0 }\
#		              len=length($$2); printf "\"%s\":\"%s\"", substr($$2, 4, len-4), $$4 } \
#		 END { printf "},\"package\":null}" }' > .cargo-checksum.json
	${RUN}${CP} ${FILESDIR}/cargo-checksum.json ${WRKSRC}/.pnpm/crates/git/node-semver/.cargo-checksum.json

	@${STEP_MSG} "Relocating npm packages for esbuild"
	${RUN}${MKDIR} ${WRKSRC}/pnpm/esm-loader/node_modules
	${RUN}${MV} ${WRKDIR}/enhanced-resolve/package ${WRKSRC}/pnpm/esm-loader/node_modules/enhanced-resolve
	${RUN}${MV} ${WRKDIR}/graceful-fs/package ${WRKSRC}/pnpm/esm-loader/node_modules/graceful-fs
	${RUN}${MV} ${WRKDIR}/tapable/package ${WRKSRC}/pnpm/esm-loader/node_modules/tapable

pre-build:
	@${STEP_MSG} "Bundling cas-loader.mjs.inc by esbuild"
	${RUN}cd ${WRKSRC}/pnpm/esm-loader && \
	esbuild --minify --bundle --platform=node --format=esm \
	--banner:js="import { createRequire as bootstrapRequire } from 'node:module'; const require = bootstrapRequire(import.meta.url);" install-register.mjs \
	--outfile=../crates/deps-restorer/src/cas-loader.mjs.inc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pnpm ${DESTDIR}${PREFIX}/bin
	${LN} -fs pnpm ${DESTDIR}${PREFIX}/bin/pn
	${LN} -fs pnpm ${DESTDIR}${PREFIX}/bin/pnx
	${LN} -fs pnpm ${DESTDIR}${PREFIX}/bin/pnpx

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
