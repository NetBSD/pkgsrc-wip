# $NetBSD$

DISTNAME=	jcode-0.99.1
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

# crates/jcode-build-meta/build.rs stamps the version banner by running git(1)
# in the source tree.  A pkgsrc build has no repository of its own, so the
# probe walks up out of ${WRKSRC} and finds whatever encloses ${PKGSRCDIR} --
# stamping that checkout's HEAD and dirty state into the binary, which reads
# "v0.86.0-dev (<unrelated hash>, dirty)" and differs between builds.  Every
# probe honours an environment override, so set them all and keep git out of
# it.  The changelog is a git-log window that a tarball build cannot produce.
MAKE_ENV+=	JCODE_RELEASE_BUILD=1
MAKE_ENV+=	JCODE_BUILD_SEMVER=${PKGVERSION_NOREV}
MAKE_ENV+=	JCODE_BUILD_GIT_HASH=pkgsrc
MAKE_ENV+=	JCODE_BUILD_GIT_TAG=v${PKGVERSION_NOREV}
MAKE_ENV+=	JCODE_BUILD_GIT_DIRTY=0
MAKE_ENV+=	JCODE_BUILD_GIT_DATE=
MAKE_ENV+=	JCODE_BUILD_CHANGELOG_RAW=

DISTFILES=					${DEFAULT_DISTFILES} agentgrep-v0.1.7.tar.gz mermaid-rs-renderer-v0.3.1.tar.gz
SITES.agentgrep-v0.1.7.tar.gz=			-${MASTER_SITE_GITHUB:=1jehuang/}agentgrep/archive/v0.1.7.tar.gz
SITES.mermaid-rs-renderer-v0.3.1.tar.gz=	-${MASTER_SITE_GITHUB:=1jehuang/}mermaid-rs-renderer/archive/v0.3.1.tar.gz

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"

post-extract:
	${MKDIR} ${WRKDIR}/vendor/agentgrep-0.1.7
	cd ${WRKDIR} && \
		${TAR} -xzf ${_DISTDIR}/agentgrep-v0.1.7.tar.gz \
		--strip-components=1 -C ${WRKDIR}/vendor/agentgrep-0.1.7
	${RUN} cd ${WRKDIR}/vendor/agentgrep-0.1.7 && \
		printf '{"package":null,"files":{}}' > .cargo-checksum.json
	${MKDIR} ${WRKDIR}/vendor/mermaid-rs-renderer-0.3.1
	cd ${WRKDIR} && \
		${TAR} -xzf ${_DISTDIR}/mermaid-rs-renderer-v0.3.1.tar.gz \
		--strip-components=1 -C ${WRKDIR}/vendor/mermaid-rs-renderer-0.3.1
	${RUN} cd ${WRKDIR}/vendor/mermaid-rs-renderer-0.3.1 && \
		printf '{"package":null,"files":{}}' > .cargo-checksum.json
# rquickjs-sys 0.14.0 ships pre-generated bindings per target triple and has no
# NetBSD ones.  Without the `bindgen` feature its build.rs does not fall back to
# generating them: it prints a cargo:warning and writes a stub that defines only
# bindings_env!(), so every FFI item is missing and the crate fails to compile.
# Enabling `bindgen` instead would pull clang/libclang into the build just to
# re-derive what amounts to the same declarations.  QuickJS's FFI surface is
# plain C scalars, pointers and structs with no Linux-specific types, so the
# glibc bindings are correct on NetBSD; alias them to the matching NetBSD triples
# rather than carry a patch per architecture.  Remove this once rquickjs ships
# NetBSD bindings upstream.
	${RUN} for f in ${WRKDIR}/vendor/rquickjs-sys-0.14.0/src/bindings/*-linux-gnu.rs; do \
		target=`${BASENAME} "$$f" | ${SED} 's/-linux-gnu/-netbsd/'`; \
		dest="${WRKDIR}/vendor/rquickjs-sys-0.14.0/src/bindings/$$target"; \
		if [ ! -f "$$dest" ]; then \
			${CP} "$$f" "$$dest"; \
		fi; \
		done

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
