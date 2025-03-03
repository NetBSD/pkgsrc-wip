# $NetBSD$

DISTNAME=	uv-0.5.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=astral-sh/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://docs.astral.sh/uv/
COMMENT=	Extremely fast Python package and project manager
LICENSE=	apache-2.0 OR mit

# for included jemalloc
USE_TOOLS+=	gmake

.include "cargo-depends.mk"

# Depends on unpublished crates. Can't use cargo.mk to fetch them.
ASYNC_ZIP_REV=		c909fda63fcafe4af496a07bfda28a5aae97e58d
PUBGRUB_REV=		648aa343486e5529953153781fc86025c73c4a61
TL_REV=			6e25b2ee2513d75385101a8ff9f591ef51f314ec
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		async_zip-${ASYNC_ZIP_REV}.tar.gz
DISTFILES+=		pubgrub-${PUBGRUB_REV}.tar.gz
DISTFILES+=		tl-${TL_REV}.tar.gz

SITES.async_zip-${ASYNC_ZIP_REV}.tar.gz+=		-${MASTER_SITE_GITHUB:=charliermarsh/}rs-async-zip/archive/${ASYNC_ZIP_REV}.tar.gz
SITES.pubgrub-${PUBGRUB_REV}.tar.gz+=			-${MASTER_SITE_GITHUB:=astral-sh/}pubgrub/archive/${PUBGRUB_REV}.tar.gz
SITES.tl-${TL_REV}.tar.gz+=				-${MASTER_SITE_GITHUB:=astral-sh/}tl/archive/${TL_REV}.tar.gz

RUST_REQ=	1.83
USE_LANGUAGES+=	c c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/uv \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/uv-globfilter \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/uvx \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
