# $NetBSD: Makefile,v 1.4 2009/07/26 08:03:29 minskim Exp $
# TeX Live Revision 13822

DISTNAME=	texlive-scripts
PKGNAME=	tex-${DISTNAME}-2009.13822

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Executables and files maintained as part of TeX Live
LICENSE=	gnu-gpl-v2 AND public-domain

CONFLICTS+=	tex-bin-texlive-[0-9]*

REPLACE_TEXLUA=		bin/rungs
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../wip/mk/tlpkg.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/texlive/rungs.tlu ${WRKSRC}/bin/rungs

.include "../../mk/bsd.pkg.mk"
