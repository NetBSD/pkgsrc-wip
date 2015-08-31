# $NetBSD: Makefile,v 1.1 2015/08/31 15:42:32 yhardy Exp $

DISTNAME=	flowfram
PKGNAME=	tex-${DISTNAME}-${TEXLIVE_REV}
TEXLIVE_REV=	35291

TEXLIVE_USE_CTAN=	YES

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Create text frames for posters, brochures or magazines

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xfor-[0-9]*:../../print/tex-xfor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
