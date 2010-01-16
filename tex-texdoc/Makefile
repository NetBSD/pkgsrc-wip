# $NetBSD: Makefile,v 1.2 2010/01/16 05:20:28 minskim Exp $
# TeX Live Revision 14095

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009.14095

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation access for TeX distributions
LICENSE=	gnu-gpl-v3 AND gnu-gpl-v2

CONFLICTS+=	teTeX-bin-[0-9]*
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk

REPLACE_PERL=		bin/texdoctk
REPLACE_TEXLUA=		bin/texdoc
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/tetex/texdoctk.pl ${WRKSRC}/bin/texdoctk
	${RMDIR} ${WRKSRC}/texmf/scripts/tetex
	${MV} ${WRKSRC}/texmf/scripts/texdoc/texdoc.tlu ${WRKSRC}/bin/texdoc
	${RMDIR} ${WRKSRC}/texmf/scripts/texdoc

.include "../../mk/bsd.pkg.mk"
