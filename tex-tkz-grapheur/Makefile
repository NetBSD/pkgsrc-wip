# $NetBSD$

DISTNAME=	tkz-grapheur
PKGNAME=	tex-${DISTNAME}-0.1.8
TEXLIVE_REV=	72226

TEXLIVE_USE_CTAN=	yes
TEXLIVE_UNVERSIONED=	yes

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tkz-grapheur
COMMENT=	A LaTeX package with tools for graph plotting (and TikZ)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems
DEPENDS+=	tex-simplekv-[0-9]*:../../print/tex-simplekv
DEPENDS+=	tex-siunitx-[0-9]*:../../print/tex-siunitx
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

# catalogue-contact-repository https://forge.apps.education.fr/pierquetcedric/package-latex-tkz-grapheur

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
