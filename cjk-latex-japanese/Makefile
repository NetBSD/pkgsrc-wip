# $NetBSD: Makefile,v 1.1.1.1 2003/04/18 09:42:23 cjep Exp $

DISTNAME=	cjk-latex-japanese-20020721
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Japanese support for CJK-LaTeX

DEPENDS+=	cjk-latex>=4.5.1:../../print/cjk-latex
DEPENDS+=	kochi-ttf-*:../../fonts/kochi-ttf

FONT_FILES=	gothic mincho

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

TEXMFMAIN=	${PREFIX}/share/texmf
TFMDIR=		${TEXMFMAIN}/fonts/tfm
TTFDIR=		${TEXMFMAIN}/fonts/truetype

X11TTFDIR=	${X11PREFIX}/lib/X11/fonts/TrueType

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
	@(cd ${TFMDIR}/kochi/${f}; \
		ttf2tfm ${TTFDIR}/kochi/${f} -P 3 -E 1 ${f}@UJIS@)
.endfor

post-install:
	# Edit special.map
	# Update ls-R
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
