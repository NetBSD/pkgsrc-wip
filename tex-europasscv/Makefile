# $NetBSD: Makefile,v 1.1 2015/08/10 21:02:17 yhardy Exp $

DISTNAME=	europasscv
PKGNAME=	tex-${DISTNAME}-${TEXLIVE_REV}
TEXLIVE_REV=	36540

TEXLIVE_USE_CTAN=	YES

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Unofficial class for the new version of the Europass curriculum vitae

DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-soul-[0-9]*:../../print/tex-soul
DEPENDS+=	tex-tabu-[0-9]*:../../print/tex-tabu
DEPENDS+=	tex-totpages-[0-9]*:../../print/tex-totpages
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
