# $NetBSD: Makefile,v 1.2 2010/01/16 05:20:28 minskim Exp $
# TeX Live Revision 14143

DISTNAME=	kpathsea
PKGNAME=	tex-${DISTNAME}-5.0.0

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Translation tables for TeX

SUPERSEDES+=	tex-bin-kpathsea-[0-9]*
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/fmtutil.cnf \
				texmf/web2c/mktex.opt \
				texmf/web2c/mktex[a-z]* \
				texmf/web2c/texmf.cnf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
