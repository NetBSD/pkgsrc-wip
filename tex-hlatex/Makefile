# $NetBSD: Makefile,v 1.3 2005/04/06 02:48:36 minskim Exp $
#

DISTNAME=	HLaTeX-0.991
PKGNAME=	tex-hlatex-0.991
WRKSRC=		${WRKDIR}/hlatex
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.bsdforum.or.kr/pub/distfiles/			\
		${MASTER_SITE_TEX_CTAN:=fonts/korean/HLaTeX/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${HLATEX_FONTS_BASE}

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://ftp.ktug.or.kr/mirrors/HLaTeX/hlatex.html
COMMENT=	LaTeX package to use Hangul (UHC/KSX1001)

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
TEXMF=		${LOCALBASE}/share/texmf

# default fonts.
HLATEX_FONTS_BASE=	uhc-myoungjo.tar.gz \
			uhc-gothic.tar.gz \
			uhc-taza.tar.gz
# documents.
HLATEX_DOC_BASE=	VERSION0.991 changelog.ks complang.tex \
			hlatex-en.html hlatex-ko.html hlatex.html \
			hlguide.bib hlguide.dvi hlguide.tex \
			news.098 news.099 readme.eng \
			uhc/uhc.ks moonttf/moonttf.ks \
			doc/compword.pdf.gz doc/compword.ps.gz \
			doc/dot.js doc/font-exam.jpg doc/hlguide.html \
			doc/hlguide.ps.gz doc/hlogo-bg.jpg doc/hlogo.jpg

HLATEX_SAMPLE_BASE=	sample/a.tex sample/p.tex sample/f.tex sample/readme.ks

# psfonts.map, special.map
# it should be downloadable, so use uhc-down.map
# why? otherwise you need nasty gs Fontmap setup...
do-build:
	${CAT}  ${TEXMF}/dvips/config/psfonts.map \
		${WRKDIR}/uhc/config/uhc-down.map \
		> ${WRKDIR}/psfonts.map
	${SED} 's@/usr/tex/share/texmf.local@${PREFIX}/share/texmf@' \
		${WRKDIR}/uhc/config/Fontmap.uhc \
		> ${WRKDIR}/Fontmap

# Installation according to readme.ks
do-install:
	# Part 1: psfonts
	# psfonts.map
	${MV} ${TEXMF}/dvips/config/psfonts.map \
		${TEXMF}/dvips/config/psfonts.map-before-hlatex
	${INSTALL_DATA} ${WRKDIR}/psfonts.map ${TEXMF}/dvips/config

	# Part 2: macros, style, font descriptions
	${MKDIR} ${TEXMF}/tex/latex/hlatex
	${MKDIR} ${TEXMF}/omega/lambda/hlatex
	${MKDIR} ${TEXMF}/omega/otp/hlatex
	${MKDIR} ${TEXMF}/omega/ocp/hlatex

	${INSTALL_DATA} ${WRKDIR}/hfont.tex \
			${WRKDIR}/hfont.sty \
			${WRKDIR}/hfont.cfg \
			${WRKDIR}/hangul.sty \
			${WRKDIR}/josa.tab \
			${WRKDIR}/uhc/latex/* \
			${WRKDIR}/moonttf/*.fd \
			${WRKDIR}/moonttf/moonttf.sty \
			${TEXMF}/tex/latex/hlatex

	${INSTALL_DATA} ${WRKDIR}/uhc/lambda/*.tex \
			${WRKDIR}/uhc/lambda/*.fd \
			${TEXMF}/omega/lambda/hlatex

	${INSTALL_DATA} ${WRKDIR}/uhc/lambda/ksx1001.otp \
			${TEXMF}/omega/otp/hlatex

	${INSTALL_DATA} ${WRKDIR}/uhc/lambda/ksx1001.ocp \
			${TEXMF}/omega/ocp/hlatex

	${INSTALL_DATA} ${WRKDIR}/contrib/halpha.bst \
			${TEXMF}/bibtex/bst/misc

	${INSTALL_DATA} ${WRKDIR}/contrib/hind.ist \
			${WRKDIR}/contrib/hglo.ist \
			${TEXMF}/makeindex

	# Part 3: documents and samples
	${MKDIR} ${TEXMF}/doc/latex/hlatex/
	for filename in ${HLATEX_DOC_BASE}; \
	do \
		${INSTALL_DATA} \
		  ${WRKDIR}/$$filename ${TEXMF}/doc/latex/hlatex; \
	done
	${MKDIR} ${TEXMF}/doc/latex/hlatex/sample
	for filename in ${HLATEX_SAMPLE_BASE}; \
	do \
		${INSTALL_DATA} \
		  ${WRKDIR}/$$filename ${TEXMF}/doc/latex/hlatex/sample; \
	done
	# fontmap...
	${INSTALL_DATA} ${WRKDIR}/Fontmap \
			${TEXMF}/doc/latex/hlatex/sample/Fontmap.uhc

	# Part 4: default mf fonts
	cd ${TEXMF}/fonts/; \
	for font in ${HLATEX_FONTS_BASE}; \
	do \
		extract_file=${DISTDIR}/$$font; \
		${EXTRACT_CMD}; \
	done
	# Part 5: rehash
	${PREFIX}/bin/texhash

.include "../../mk/bsd.pkg.mk"
