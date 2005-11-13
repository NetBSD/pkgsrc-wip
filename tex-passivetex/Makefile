# $NetBSD: Makefile,v 1.4 2005/11/13 06:17:47 minskim Exp $
#

DISTNAME=	passivetex
PKGNAME=	tex-${DISTNAME}-1.24
CATEGORIES=	print
MASTER_SITES=	http://www.tei-c.org.uk/Software/passivetex/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tei-c.org.uk/Software/passivetex/
COMMENT=	TeX macros for formatting objects

DEPENDS+=	tex-xmltex>=1.9:../../textproc/tex-xmltex

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	@cd ${WRKSRC}; TEXMFMAIN=$$(kpsewhich -expand-var '$$TEXMFMAIN'); \
	${MKDIR} -m 555 $$TEXMFMAIN/tex/passivetex; \
	${INSTALL_DATA} dummyels.sty fotex.xmt fotex.sty mlnames.sty \
		nomulticol.sty ucharacters.sty unicode.sty \
		$$TEXMFMAIN/tex/passivetex;
	${LOCALBASE}/bin/mktexlsr

.include "../../mk/bsd.pkg.mk"
