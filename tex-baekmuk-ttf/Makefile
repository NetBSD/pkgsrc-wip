# $NetBSD: Makefile,v 1.4 2009/04/09 01:05:16 jsonn Exp $

DISTNAME=	tex-baekmuk-ttf-2.2
CATEGORIES=	fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	TeX fonts based on Baekmuk TrueType fonts

DEPENDS+=	ttf2pk>=1.3.1:../../fonts/ttf2pk
DEPENDS+=	baekmuk-ttf-2.2*:../../fonts/baekmuk-ttf

FONT_FILES=	batang dotum gulim hline

TEX_ACCEPTED=	teTeX3
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}

TFMDIR=		${TEXMFDIRS}/fonts/tfm
TTFDIR=		${TEXMFDIRS}/fonts/truetype
SFDDIR=		${TEXMFDIRS}/ttf2tfm/base

X11TTFDIR=	${X11PREFIX}/lib/X11/fonts/TTF

do-build:
.for f in ${FONT_FILES}
	${MKDIR} ${WRKSRC}/${f}
	cd ${WRKSRC}/${f}; \
		ttf2tfm ${X11TTFDIR}/${f}.ttf -P 3 -E 1 ${f}@${SFDDIR}/UKS@;
.endfor

do-install:
	# Install fonts
	${INSTALL_DATA_DIR} ${TTFDIR}/baekmuk
.for f in ${FONT_FILES}
	${LN} -fs ${X11TTFDIR}/${f}.ttf ${TTFDIR}/baekmuk/${f}.ttf
	${INSTALL_DATA_DIR} ${TFMDIR}/baekmuk/${f}
	${INSTALL_DATA} ${WRKSRC}/${f}/*.tfm ${TFMDIR}/baekmuk/${f}
.endfor

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
