# $NetBSD$

DISTNAME=	dmarc-report-viewer-2.5.1
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

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
