# $NetBSD: Makefile,v 1.5 2004/10/26 00:43:43 rxg Exp $

DISTNAME=	CJK-4_5.2
PKGNAME=	cjk-latex-4.5.2
CATEGORIES=	print
MASTER_SITES=	http://www.feyrer.de/Misc/ \
		${MASTER_SITE_LOCAL}	# relocate to MSL when moving to pkgsrc

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	The CJK (Chinese, Japanese, Korean) package for LaTeX

DEPENDS+=	teTeX-bin>=2:../../print/teTeX-bin
DEPENDS+=	ttf2pk>=1.3.1:../../fonts/ttf2pk

TEXMFMAIN=	${PREFIX}/share/texmf
TTFDIR=		${TEXMFMAIN}/fonts/truetype

MAKE_ENV+=	TEXMFMAIN=${TEXMFMAIN}

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

FILES_SUBST=		TEXMFMAIN=${TEXMFMAIN}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

post-extract:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.cjk
	${CHMOD} +x ${WRKSRC}/utils/hbf2gf/configure

post-patch:
	${FIND} ${WRKSRC}/texinput -type f -name '*.orig' | ${XARGS} ${RM} -f

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_DATA_DIR} ${TTFDIR}

	# Edit ttfonts.map texmf.cnf
	# Update ls-R
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
