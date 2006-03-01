# $NetBSD: Makefile,v 1.2 2006/03/01 13:15:24 rxg Exp $

DISTNAME=	tex-arphic-ttf-2.11
CATEGORIES=	fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	TeX fonts based on Arphic TrueType fonts

DEPENDS+=	ttf2pk>=1.3.1:../../fonts/ttf2pk
DEPENDS+=	arphic-ttf-2.11*:../../fonts/arphic-ttf

FONT_FILES=	bkai00mp bsmi00lp gbsn00lp gkai00mp

TEX_ACCEPTED=	teTeX3
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}

TFMDIR=		${TEXMFDIRS}/fonts/tfm
TTFDIR=		${TEXMFDIRS}/fonts/truetype
SFDDIR=		${TEXMFDIRS}/ttf2tfm/base

X11TTFDIR=	${X11PREFIX}/lib/X11/fonts/TTF

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

do-build:
.for f in ${FONT_FILES}
	${MKDIR} ${WRKSRC}/${f}
	cd ${WRKSRC}/${f}; \
	if [ ${f} = bkai00mp ] || [ ${f} = bsmi00lp ]; then \
		ttf2tfm ${X11TTFDIR}/${f}.ttf -P 3 -E 1 ${f}@${SFDDIR}/UBig5@; \
	else \
		ttf2tfm ${X11TTFDIR}/${f}.ttf -P 3 -E 1 ${f}@${SFDDIR}/UGB@; \
	fi
.endfor

do-install:
	# Install fonts
	${INSTALL_DATA_DIR} ${TTFDIR}/arphic
.for f in ${FONT_FILES}
	${LN} -fs ${X11TTFDIR}/${f}.ttf ${TTFDIR}/arphic/${f}.ttf
	${INSTALL_DATA_DIR} ${TFMDIR}/arphic/${f}
	${INSTALL_DATA} ${WRKSRC}/${f}/*.tfm ${TFMDIR}/arphic/${f}
.endfor

post-install:
	# Edit special.map ttfonts.map
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
