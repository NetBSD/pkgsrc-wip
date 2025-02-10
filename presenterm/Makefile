# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	presenterm-0.10.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mfontanini/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mfontanini.github.io/presenterm/
COMMENT=	Markdown terminal slideshow tool
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
