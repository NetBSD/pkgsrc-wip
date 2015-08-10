# $NetBSD: Makefile,v 1.1 2015/08/10 20:38:46 yhardy Exp $

DISTNAME=	tikzposter
PKGNAME=	tex-${DISTNAME}-${TEXLIVE_REV}
TEXLIVE_REV=	32732

TEXLIVE_USE_CTAN=	YES

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Create scientific posters using TikZ

DEPENDS+=	tex-ae-[0-9]*:../../fonts/tex-ae
DEPENDS+=	tex-a0poster-[0-9]*:../../print/tex-a0poster
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-extsizes-[0-9]*:../../print/tex-extsizes
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xstring-[0-9]*:../../wip/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
