# $NetBSD$

PKGNAME=	${DISTNAME:C/-rc\./rc/}
DISTNAME=	pnpm-12.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pnpm/}
GITHUB_TAG=	refs/tags/v${DISTNAME:C/^[^-]*-//}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://pnpm.io/
COMMENT=	Fast, disk space efficient package manager
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

RUST_REQ=	1.98

INSTALLATION_DIRS=	bin

CARGO_ARGS=		build --release --bin pnpm ${DEFAULT_CARGO_ARGS}

# Depends on unpublished crates. Can't use cargo.mk to fetch them.
NODE_SEMVER_REV=	3d74d6b7f4de1de2006cf2f7663aac09de65b1f6
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		node-semver-${NODE_SEMVER_REV}.tar.gz

SITES.node-semver-${NODE_SEMVER_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=pnpm/}node-semver-rs/archive/${NODE_SEMVER_REV}.tar.gz

post-extract:
	@${STEP_MSG} "Relocating cargo crates in the pnpm way ;)"
	${RUN}${MKDIR} ${WRKSRC}/.pnpm/crates
	${RUN}${LN} -fs ${CARGO_VENDOR_DIR} ${WRKSRC}/.pnpm/crates/crates-io
	${RUN}${MKDIR} ${WRKSRC}/.pnpm/crates/git
	${RUN}${MV} ${WRKDIR}/node-semver-rs-${NODE_SEMVER_REV} ${WRKSRC}/.pnpm/crates/git/node-semver

	@${STEP_MSG} "Generating .cargo-checksum.json for node-semver"
	${RUN}cd ${WRKSRC}/.pnpm/crates/git/node-semver && \
	${FIND} . -type f ! -name .cargo-checksum.json -print0 | xargs -0 ${DIGEST} sha256 | ${AWK} \
	'BEGIN { first=1; printf "{\"files\":{" } \
	 /^SHA256 / { if (first==0) { printf "," } else { first=0 }\
	              len=length($$2); printf "\"%s\":\"%s\"", substr($$2, 4, len-4), $$4 } \
	 END { printf "},\"package\":null}" }' > .cargo-checksum.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pnpm ${DESTDIR}${PREFIX}/bin
	${LN} -fs pnpm ${DESTDIR}${PREFIX}/bin/pn
	${LN} -fs pnpm ${DESTDIR}${PREFIX}/bin/pnx
	${LN} -fs pnpm ${DESTDIR}${PREFIX}/bin/pnpx

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
