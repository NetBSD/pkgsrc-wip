# $NetBSD: Makefile,v 1.1.1.1 2003/10/11 21:45:01 minskim Exp $
#

DISTNAME=	xmltex-1.9
PKGNAME=	tex-${DISTNAME}
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/xmltex/base/}
DISTFILES=	englishutf16.xml englishutf8.xml \
		iso-8859-1.xmt iso-8859-2.xmt koi8-r.xmt \
		langtest.tex langtest.xml langtest.xmt \
		manual.html manual.tex manual.xml manual.xsl \
		mathml2.xmt pdfxmltex.ini portugeselatin1.xml readme.txt \
		russiankoi8.xml russianutf8.xml sec.xmt tei.xmt \
		testascii.cfg testascii.tex testascii.xml testsec.tex \
		testsec.xml utf-16.xmt windows-1250.xmt \
		xmltex.cfg xmltex.ini xmltex.tex

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.dcarlisle.demon.co.uk/xmltex/manual.html
COMMENT=	Non-validating XML parser implemented in TeX

DEPENDS+=	teTeX{,2}-bin-[0-9]*:../../print/teTeX-bin

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes

DIST_SUBDIR=	${PKGBASE}

do-extract:
.for FILE in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${FILE} ${WRKSRC}
.endfor
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@cd ${WRKSRC}; TEXMFMAIN=$$(kpsewhich -expand-var '$$TEXMFMAIN'); \
	${INSTALL_DATA} xmltex.fmt pdfxmltex.fmt $$TEXMFMAIN/web2c;
	${LOCALBASE}/bin/mktexlsr

.include "../../mk/bsd.pkg.mk"
