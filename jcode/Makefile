# $NetBSD$

DISTNAME=	jcode-0.81.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=1jehuang/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/1jehuang/jcode/
COMMENT=	LLM harness
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config tar

BUILD_DEPENDS+=	lld-[0-9]*:../../wip/lld

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}

# Use lld linker instead of GNU ld - much less memory during final link.
# Max codegen units + thin LTO spread LLVM work across smaller parallel invocations.
RUSTFLAGS+=	-C link-arg=-fuse-ld=lld
MAKE_ENV+=	CARGO_PROFILE_RELEASE_CODEGEN_UNITS=16
MAKE_ENV+=	CARGO_PROFILE_RELEASE_LTO=thin

DISTFILES=					${DEFAULT_DISTFILES} agentgrep-v0.1.6.tar.gz mermaid-rs-renderer-v0.3.1.tar.gz
SITES.agentgrep-v0.1.6.tar.gz=			-${MASTER_SITE_GITHUB:=1jehuang/}agentgrep/archive/v0.1.6.tar.gz
SITES.mermaid-rs-renderer-v0.3.1.tar.gz=	-${MASTER_SITE_GITHUB:=1jehuang/}mermaid-rs-renderer/archive/v0.3.1.tar.gz

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"

post-extract:
	${MKDIR} ${WRKDIR}/vendor/agentgrep-0.1.6
	cd ${WRKDIR} && \
		${TAR} -xzf ${_DISTDIR}/agentgrep-v0.1.6.tar.gz \
		--strip-components=1 -C ${WRKDIR}/vendor/agentgrep-0.1.6
	${RUN} cd ${WRKDIR}/vendor/agentgrep-0.1.6 && \
		printf '{"package":null,"files":{}}' > .cargo-checksum.json
	${MKDIR} ${WRKDIR}/vendor/mermaid-rs-renderer-0.3.1
	cd ${WRKDIR} && \
		${TAR} -xzf ${_DISTDIR}/mermaid-rs-renderer-v0.3.1.tar.gz \
		--strip-components=1 -C ${WRKDIR}/vendor/mermaid-rs-renderer-0.3.1
	${RUN} cd ${WRKDIR}/vendor/mermaid-rs-renderer-0.3.1 && \
		printf '{"package":null,"files":{}}' > .cargo-checksum.json
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
