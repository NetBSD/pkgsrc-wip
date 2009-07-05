# $NetBSD: Makefile,v 1.1.1.1 2009/07/05 22:37:26 minskim Exp $
# TeX Live Revision 13822

DISTNAME=	texlive-scripts
PKGNAME=	tex-${DISTNAME}-2009.13822

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Executables and files maintained as part of TeX Live

CONFLICTS+=	tex-bin-texlive-[0-9]*
DEPENDS+=	luatex-[0-9]*:../../print/luatex

FIND_PREFIX:=	TEXLUA_PREFIX=texlua
.include "../../mk/find-prefix.mk"

REPLACE_INTERPRETER=	texlua
REPLACE.texlua.old=	.*texlua
REPLACE.texlua.new=	${TEXLUA_PREFIX}/bin/texlua
REPLACE_FILES.texlua=	bin/rungs

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../wip/mk/tlpkg.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/texlive/rungs.tlu ${WRKSRC}/bin/rungs

.include "../../mk/bsd.pkg.mk"
