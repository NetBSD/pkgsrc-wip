# $NetBSD$

DISTNAME=	firecrawl_anydoc-0.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/firecrawl_//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_GITHUB:=firecrawl/}
GITHUB_PROJECT=	anydoc
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://firecrawl.github.io/anydoc/
COMMENT=	Convert all kinds of inputs to markdown
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin-[0-9]*:../../devel/py-maturin

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
