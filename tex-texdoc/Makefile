# $NetBSD: Makefile,v 1.1.1.1 2009/07/06 18:49:31 minskim Exp $
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

.include "../../wip/mk/tlpkg.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/tetex/texdoctk.pl ${WRKSRC}/bin/texdoctk
	${RMDIR} ${WRKSRC}/texmf/scripts/tetex
	${MV} ${WRKSRC}/texmf/scripts/texdoc/texdoc.tlu ${WRKSRC}/bin/texdoc
	${RMDIR} ${WRKSRC}/texmf/scripts/texdoc

.include "../../mk/bsd.pkg.mk"
