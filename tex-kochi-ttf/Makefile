# $NetBSD: Makefile,v 1.4 2009/04/09 01:04:38 jsonn Exp $

DISTNAME=	tex-kochi-ttf-20030809
CATEGORIES=	fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	TeX fonts based on Kochi TrueType fonts

DEPENDS+=	ttf2pk>=1.3.1:../../fonts/ttf2pk
DEPENDS+=	kochi-ttf-20030809*:../../fonts/kochi-ttf

FONT_FILES=	gothic mincho

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
		ttf2tfm ${X11TTFDIR}/kochi-${f}.ttf -P 3 -E 1 ${f}@${SFDDIR}/UJIS@;
.endfor

do-install:
	# Install fonts
	${INSTALL_DATA_DIR} ${TTFDIR}/kochi
.for f in ${FONT_FILES}
	${LN} -fs ${X11TTFDIR}/kochi-${f}.ttf ${TTFDIR}/kochi/${f}.ttf
	${INSTALL_DATA_DIR} ${TFMDIR}/kochi/${f}
	${INSTALL_DATA} ${WRKSRC}/${f}/*.tfm ${TFMDIR}/kochi/${f}
.endfor

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
