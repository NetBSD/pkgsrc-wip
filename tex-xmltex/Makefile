# $NetBSD: Makefile,v 1.3 2003/12/25 12:19:27 jmmv Exp $
#

DISTNAME=	base
PKGNAME=	tex-xmltex-1.9
WRKSRC=		${WRKDIR}/base
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/macros/xmltex/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.dcarlisle.demon.co.uk/xmltex/manual.html
COMMENT=	Non-validating XML parser implemented in TeX

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

NO_CONFIGURE=	yes

DIST_SUBDIR=	${PKGBASE}

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@cd ${WRKSRC}; TEXMFMAIN=$$(kpsewhich -expand-var '$$TEXMFMAIN'); \
	${INSTALL_DATA} xmltex.fmt pdfxmltex.fmt $$TEXMFMAIN/web2c;
	${LOCALBASE}/bin/mktexlsr

.include "../../mk/bsd.pkg.mk"
