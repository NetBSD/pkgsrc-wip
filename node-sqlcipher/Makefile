# $NetBSD$

.include "../../wip/signal-desktop/versions.mk"

DISTNAME=		node-sqlcipher-${SQLCIPHER_VER}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=signalapp/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

#TODO: MASTER_SITES for node_modules
DISTFILES+=		node-sqlcipher-node_modules-${SQLCIPHER_VER}.tar.gz
DISTFILES+=		${DEFAULT_DISTFILES}

MAINTAINER=		kikadf@NetBSD.org
HOMEPAGE=		https://github.com/signalapp/node-sqlcipher/
COMMENT=		Node.js addon wrapping sqlcipher and FTS5 segmenting APIs
LICENSE=		gnu-agpl-v3

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
CARGO_WRKSRC=		${WRKSRC}/deps/extension

SUBST_CLASSES+=		gh
SUBST_STAGE.gh=		pre-configure
SUBST_MESSAGE.gh=	Set signal-tokenizer path
SUBST_FILES.gh+=	deps/extension/Cargo.toml
SUBST_VARS.gh+=		SIGNAL_TOKENIZER_HASH
SUBST_VARS.gh+=		WRKDIR

CARGO_GITHUB_CRATES=	signalapp Signal-FTS5-Extension ${SIGNAL_TOKENIZER_HASH}
SUBST_NOOP_OK.gitcrate=	yes

NODE_VERSIONS_ACCEPTED=	${NODE_MAJOR}

INSTALLATION_DIRS+=	lib

NPM_FLAGS=		--offline
NPM_FLAGS+=		--cache ${WRKDIR}/node-sqlcipher-node_modules-${PKGVERSION_NOREV}

.include "../../mk/bsd.fast.prefs.mk"

.if defined(SIGNAL_MAINTAINER)
# For create npm cache tarball
USE_TOOLS+=		bsdtar

MNPM_FLAGS=		--ignore-scripts --no-progress --no-audit --no-fund --no-update-notifier
MNPM_FLAGS+=		--cache ${WRKDIR}/node-sqlcipher-tmp/node-sqlcipher-node_modules-${PKGVERSION_NOREV}

.PHONY: cache-tarball
cache-tarball:
	${MKDIR} ${WRKDIR}/node-sqlcipher-tmp/node-sqlcipher-node_modules-${PKGVERSION_NOREV}
	${TOOLS_PATH.bsdtar} -zxf ${DISTDIR}/${DISTNAME}.tar.gz \
		--strip-components=1 -C ${WRKDIR}/node-sqlcipher-tmp
	cd ${WRKDIR}/node-sqlcipher-tmp && \
		npm install ${MNPM_FLAGS}
	cd ${WRKDIR}/node-sqlcipher-tmp && \
		${TOOLS_PATH.bsdtar} -czf ${WRKDIR}/node-sqlcipher-node_modules-${PKGVERSION_NOREV}.tar.gz \
		node-sqlcipher-node_modules-${PKGVERSION_NOREV}
.endif

do-configure:

do-build: do-cargo-build
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm_config_nodedir=${PREFIX} npm install ${NPM_FLAGS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/Release/obj.target/node_sqlcipher.node \
		${DESTDIR}${PREFIX}/lib


.include "cargo-depends.mk"

BUILDLINK_DEPMETHOD.nodejs=	build
.include "../../lang/nodejs/nodeversion.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
