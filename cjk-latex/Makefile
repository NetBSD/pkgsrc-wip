# $NetBSD: Makefile,v 1.3 2003/08/29 11:49:28 thomasklausner Exp $

DISTNAME=	cjk-4.5.1
PKGNAME=	cjk-latex-4.5.1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ffii.org/pub/cjk/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	The CJK package for LaTeX

DEPENDS+=	teTeX-bin>=1.0.7nb1:../../print/teTeX-bin
DEPENDS+=	freetype-lib>=1.3.1:../../graphics/freetype-lib

TEXMFMAIN=	${PREFIX}/share/texmf
TTFDIR=		${TEXMFMAIN}/fonts/truetype

MAKE_ENV+=	TEXMFMAIN=${TEXMFMAIN}

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

FILES_SUBST=		TEXMFMAIN=${TEXMFMAIN}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

post-extract:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.cjk

post-patch:
	${FIND} ${WRKSRC}/texinput -type f -name '*.orig' | ${XARGS} ${RM} -f

post-build:
	@(cd ../../graphics/freetype-lib; ${MAKE} build; \
	  cd ${WRKDIR:T}/freetype-1.3.1/contrib/ttf2pk; \
	  ./configure --prefix=${PREFIX} --with-kpathsea-dir=${LOCALBASE}; \
	  ${MAKE} depend all; ${PATCH} < ${FILESDIR}/UBig5.sfd.diff; \
	  ${RM} -f data/UBig5.sfd.orig)

pre-install:
	@(cd ../../graphics/freetype-lib; \
	  cd ${WRKDIR:T}/freetype-1.3.1/contrib/ttf2pk; \
	  ${MAKE} install; ${INSTALL_DATA_DIR} ${TEXMFMAIN}/ttf2pk; \
	  ${INSTALL_DATA} data/* ${TEXMFMAIN}/ttf2pk)
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_DATA_DIR} ${TTFDIR}

	# Edit ttfonts.map texmf.cnf
	# Update ls-R
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
