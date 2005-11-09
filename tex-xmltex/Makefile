# $NetBSD: Makefile,v 1.5 2005/11/09 09:38:40 jtonio Exp $
#

DISTNAME=	base
PKGNAME=	tex-xmltex-1.9
WRKSRC=		${WRKDIR}/base
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/xmltex/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.dcarlisle.demon.co.uk/xmltex/manual.html
COMMENT=	Non-validating XML parser implemented in TeX

NO_CONFIGURE=	yes

DIST_SUBDIR=	${PKGBASE}

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_DATA} xmltex.fmt pdfxmltex.fmt ${PKG_TEXMFPREFIX}/web2c;
	${LOCALBASE}/bin/mktexlsr

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
