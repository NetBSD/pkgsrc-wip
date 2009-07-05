# $NetBSD: Makefile,v 1.3 2009/07/05 23:54:52 minskim Exp $
# TeX Live Revision 13822

DISTNAME=	texlive-scripts
PKGNAME=	tex-${DISTNAME}-2009.13822

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Executables and files maintained as part of TeX Live
LICENSE=	gnu-gpl-v2 AND public-domain

CONFLICTS+=	tex-bin-texlive-[0-9]*
DEPENDS+=	luatex-[0-9]*:../../print/luatex

REPLACE_TEXLUA=		bin/rungs
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../wip/mk/tlpkg.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/texlive/rungs.tlu ${WRKSRC}/bin/rungs

.include "../../mk/bsd.pkg.mk"
