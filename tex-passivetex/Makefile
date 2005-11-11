# $NetBSD: Makefile,v 1.3 2005/11/11 22:50:24 kristerw Exp $
#

DISTNAME=	passivetex
PKGNAME=	tex-${DISTNAME}-1.24
CATEGORIES=	print
MASTER_SITES=	http://www.tei-c.org.uk/Software/passivetex/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tei-c.org.uk/Software/passivetex/
COMMENT=	TeX macros for formatting objects

DEPENDS+=	tex-xmltex>=1.9:../../wip/tex-xmltex

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
