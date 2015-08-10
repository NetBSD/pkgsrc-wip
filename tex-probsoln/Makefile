# $NetBSD: Makefile,v 1.1 2015/08/10 20:54:41 yhardy Exp $

DISTNAME=	probsoln
PKGNAME=	tex-${DISTNAME}-${TEXLIVE_REV}
TEXLIVE_REV=	29371

TEXLIVE_USE_CTAN=	YES

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generate problem sheets and their solution sheets

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
