# $NetBSD: Makefile,v 1.8 2005/02/02 05:35:16 rxg Exp $

DISTNAME=	cjk-latex-korean-20020721
WRKSRC=		${WRKDIR}
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Korean support for CJK-LaTeX

#DEPENDS+=	cjk-latex>=4.5.2:../../print/cjk-latex
DEPENDS+=	cjk-latex>=4.5.2:../../wip/cjk-latex
DEPENDS+=	ttf2pk>=1.3.1:../../fonts/ttf2pk
DEPENDS+=	baekmuk-ttf-[0-9]*:../../fonts/baekmuk-ttf

FONT_FILES=	batang dotum gulim hline

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
	${INSTALL_DATA_DIR} ${TTFDIR}/baekmuk
.for f in ${FONT_FILES}
	${LN} -fs ${X11TTFDIR}/${f}.ttf ${TTFDIR}/baekmuk/${f}.ttf
	${INSTALL_DATA_DIR} ${TFMDIR}/baekmuk/${f}
	@(cd ${TFMDIR}/baekmuk/${f}; \
		ttf2tfm ${TTFDIR}/baekmuk/${f} -P 3 -E 1 ${f}@UKS@)
.endfor

post-install:
	# Edit special.map
	# Update ls-R
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
