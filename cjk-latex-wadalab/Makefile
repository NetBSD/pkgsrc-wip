# $NetBSD: Makefile,v 1.2 2005/02/10 00:41:26 hubertf Exp $

DISTNAME=	cjk-latex-wadalab-4.5.2
CATEGORIES=	print
FONTARCHS=	wadalab-gothic-0-13.5.tar.gz \
		wadalab-maru-0-8.4.tar.gz \
		wadalab-maru-1-8.tar.gz \
		wadalab-mincho-0-12.8.tar.gz \
		wadalab-mincho-0-8.4.tar.gz \
		wadalab-mincho-1-8.tar.gz \
		wadalab-sym.7.tar.gz
ALLARCHS=	CJK-4_5.2.tar.gz \
		${FONTARCHS}
EXTRACT_ONLY=	${ALLARCHS}
DISTFILES=	${ALLARCHS} \
		wftodm.c
SITES_JK-4_5.2.tar.gz= \
		http://www.feyrer.de/Misc/ \
		${MASTER_SITE_LOCAL}	# relocate to MSL when moving to pkgsrc
SITES_wftodm.c= \
		ftp://ftp.dante.de/pub/tex/support/ghostscript/3rdparty/fonts/kanji/Font/tools/
.for f in ${FONTARCHS}
SITES_${f}+= \
		ftp://ftp.dante.de/pub/tex/support/ghostscript/3rdparty/fonts/kanji/Font/
.endfor

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://cjk.ffii.org/
COMMENT=	Wadalab japanese font for cjk-latex

DEPENDS+=	cjk-latex>=4.5.2:../../wip/cjk-latex
BUILD_DEPENDS+=	t1utils-[0-9]*:../../fonts/t1utils

TEXMFMAIN=	${PREFIX}/share/texmf
FDDIR=		${TEXMFMAIN}/tex/latex/CJK/JIS
TFMDIR=		${TEXMFMAIN}/fonts/tfm/public/wadalab
PFBDIR=		${TEXMFMAIN}/fonts/type1/public/wadalab
MAPDIR=		${TEXMFMAIN}/dvips/config
WRKSRC=		${WRKDIR}

MAKE_ENV+=	TEXMFMAIN=${TEXMFMAIN}

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

FILES_SUBST=		MAPDIR=${MAPDIR}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

post-extract:
		${CP} ${DISTDIR}/wftodm.c ${WRKDIR}

do-build:
	cd ${WRKDIR}; \
	gcc -O wftodm.c -o wftodm; \
	${MKDIR} f ; \
	cd f ; \
	../wftodm -FontBase dg ../wadalab-sym/jis*.ps ../wadalab-gothic-0-13/goth-*.ps; \
	../wftodm -FontBase dm ../wadalab-sym/jis*.ps ../wadalab-mincho-0-12/min-*.ps; \
	../wftodm -FontBase mc ../wadalab-sym/jis*.ps ../wadalab-mincho-0-8/min-*.ps; \
	../wftodm -FontBase mr ../wadalab-sym/jis*.ps ../wadalab-maru-0-8/maru-*.ps; \
	../wftodm -FontBase mc2 ../wadalab-mincho-1-8/min*.ps; \
	../wftodm -FontBase mr2 ../wadalab-maru-1-8/maru*.ps; \
	${SH} ../CJK-4_5.2/contrib/wadalab/makefont

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_DATA_DIR} ${TFMDIR}
	${INSTALL_DATA_DIR} ${PFBDIR}
	${INSTALL_DATA_DIR} ${MAPDIR}
	${INSTALL_DATA} ${WRKDIR}/f/*.pfb ${PFBDIR}
	${INSTALL_DATA} ${WRKDIR}/f/*.tfm ${TFMDIR}
	${INSTALL_DATA} ${WRKDIR}/CJK-4_5.2/contrib/wadalab/wadalab.map ${MAPDIR}
	${INSTALL_DATA} ${WRKDIR}/CJK-4_5.2/contrib/wadalab/*.fd* ${FDDIR}
	# Update updmap.cfg etc. by running updmap
	@${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
