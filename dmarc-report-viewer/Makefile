# $NetBSD$

DISTNAME=	dmarc-report-viewer-2.3.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=cry-inc/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cry-inc/dmarc-report-viewer/
COMMENT=	Lightweight Standalone DMARC Report Viewer with IMAP Client
LICENSE=	mit

# bindgen needs libclang
TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

USE_LANGUAGES=	c
USE_TOOLS+=	cmake

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
TOKIO_IMAP_REV=		55e6c27189c7086a5726fe8bf224ba5c24d19d0c
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		tokio-imap-${TOKIO_IMAP_REV}.tar.gz

SITES.tokio-imap-${TOKIO_IMAP_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=djc/}tokio-imap/archive/${TOKIO_IMAP_REV}.tar.gz

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
