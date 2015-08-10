# $NetBSD: Makefile,v 1.1 2015/08/10 20:23:05 yhardy Exp $

DISTNAME=	cuisine
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	34453

TEXLIVE_USE_CTAN=	YES

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Typeset recipes in LaTeX

DEPENDS+=	tex-units-[0-9]*:../../print/tex-units

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
