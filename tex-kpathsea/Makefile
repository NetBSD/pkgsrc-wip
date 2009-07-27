# $NetBSD: Makefile,v 1.1.1.1 2009/07/27 09:43:54 minskim Exp $
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

.include "../../wip/mk/tlpkg.mk"
.include "../../mk/bsd.pkg.mk"
