# $NetBSD: Makefile,v 1.8 2005/03/19 10:43:29 hubertf Exp $

DISTNAME=	cjk-latex-chinese-20020721
WRKSRC=		${WRKDIR}
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Chinese BIG5/GB support for CJK-LaTeX

#DEPENDS+=	cjk-latex>=4.5.2:../../print/cjk-latex
DEPENDS+=	cjk-latex>=4.5.2:../../wip/cjk-latex
DEPENDS+=	ttf2pk>=1.3.1:../../fonts/ttf2pk
DEPENDS+=	arphic-ttf-[0-9]*:../../fonts/arphic-ttf

FONT_FILES=	bkai00mp bsmi00lp gbsn00lp gkai00mp

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

TEXMFMAIN=	${PREFIX}/share/texmf
TFMDIR=		${TEXMFMAIN}/fonts/tfm
TTFDIR=		${TEXMFMAIN}/fonts/truetype

X11TTFDIR=	${X11PREFIX}/lib/X11/fonts/TTF
SFDDIR=         ${TEXMFMAIN}/ttf2tfm/base

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

FILES_SUBST=		TEXMFMAIN=${TEXMFMAIN}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	# Install fonts
	${INSTALL_DATA_DIR} ${TTFDIR}/arphic
.for f in ${FONT_FILES}
	${LN} -fs ${X11TTFDIR}/${f}.ttf ${TTFDIR}/arphic/${f}.ttf
	${INSTALL_DATA_DIR} ${TFMDIR}/arphic/${f}
	(cd ${TFMDIR}/arphic/${f}; \
	  if [ ${f} = bkai00mp ] || [ ${f} = bsmi00lp ]; then \
		ttf2tfm ${TTFDIR}/arphic/${f} -P 3 -E 1 ${f}@${SFDDIR}/UBig5@; \
	  else \
		ttf2tfm ${TTFDIR}/arphic/${f} -P 3 -E 1 ${f}@${SFDDIR}/UGB@; \
	  fi)
.endfor

post-install:
	# Edit special.map
	# Update ls-R
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
