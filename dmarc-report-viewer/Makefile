# $NetBSD$

DISTNAME=	dmarc-report-viewer-2.1.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=cry-inc/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cry-inc/dmarc-report-viewer/
COMMENT=	Lightweight Standalone DMARC Report Viewer with IMAP Client
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	cmake

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
