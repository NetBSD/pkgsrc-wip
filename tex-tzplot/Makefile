# $NetBSD$

DISTNAME=	tzplot
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	64537

TEXLIVE_USE_CTAN=	yes
TEXLIVE_UNVERSIONED=	yes

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tzplot
COMMENT=	Plot graphs with TikZ abbreviations
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
