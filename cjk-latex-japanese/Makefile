# $NetBSD: Makefile,v 1.7 2005/02/02 05:34:02 rxg Exp $

DISTNAME=	cjk-latex-japanese-20020721
WRKSRC=		${WRKDIR}
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Japanese support for CJK-LaTeX

#DEPENDS+=	cjk-latex>=4.5.2:../../print/cjk-latex
DEPENDS+=	cjk-latex>=4.5.2:../../wip/cjk-latex
DEPENDS++	ttf2pk>=1.3.1:../../fonts/ttf2pk
DEPENDS+=	kochi-ttf-[0-9]*:../../fonts/kochi-ttf

FONT_FILES=	gothic mincho

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

TEXMFMAIN=	${PREFIX}/share/texmf
TFMDIR=		${TEXMFMAIN}/fonts/tfm
TTFDIR=		${TEXMFMAIN}/fonts/truetype

X11TTFDIR=	${X11PREFIX}/lib/X11/fonts/TTF

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

FILES_SUBST=		TEXMFMAIN=${TEXMFMAIN}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	# Install fonts
	${INSTALL_DATA_DIR} ${TTFDIR}/kochi
.for f in ${FONT_FILES}
	${LN} -fs ${X11TTFDIR}/kochi-${f}.ttf ${TTFDIR}/kochi/${f}.ttf
	${INSTALL_DATA_DIR} ${TFMDIR}/kochi/${f}
	(cd ${TFMDIR}/kochi/${f}; \
		ttf2tfm ${TTFDIR}/kochi/${f} -P 3 -E 1 ${f}@UJIS@)
.endfor

post-install:
	# Edit special.map
	# Update ls-R
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
