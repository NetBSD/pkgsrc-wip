# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	kakoune-lsp-18.2.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=kakoune-lsp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kakoune-lsp/kakoune-lsp/
COMMENT=	Language Server Protocol Client for Kakoune
LICENSE=	unlicense

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
