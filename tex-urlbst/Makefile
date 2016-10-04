# $NetBSD$

DISTNAME=	urlbst
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	29803
TEXLIVE_USE_CTAN=	yes

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/urlbst
COMMENT=	Web support for BibTeX
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	perl:run
REPLACE_PERL+=	texmf-dist/scripts/urlbst/urlbst

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
