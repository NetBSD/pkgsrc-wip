# $NetBSD: Makefile,v 1.4 2012/11/23 22:33:38 othyro Exp $
#

DISTNAME=	urwfonts-8.71
PKGNAME=	ghostpcl-${DISTNAME:S/-/-ttf-/}
#PKGNAME=	ghostpcl-urwfonts-ttf-8.71
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/ghostscript/AFPL/GhostPCL/}
DISTFILES=	${DISTNAME}.tar.bz2 urwfonts-1.41.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.ghostscript.com/GhostPCL.html
COMMENT=	PCL 80 std ttf fonts under AFPL (except for PostScript 35 std fonts)
#LICENSE=	aladdin-free-public-license

RESTRICTED=		Under AFPL (Distribution with fee is prohibitted.)
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	A028-Ext.ttf \
		A028-Med.ttf \
		A030-Bol.ttf \
		A030-BolIta.ttf \
		A030-Ita.ttf \
		A030-Reg.ttf \
		AntiqueOlive-Bol.ttf \
		AntiqueOlive-Ita.ttf \
		AntiqueOlive-Reg.ttf \
		ClarendonURW-BolCon.ttf \
		Coronet.ttf \
		Dingbats.ttf \
		GaramondNo8-Ita.ttf \
		GaramondNo8-Med.ttf \
		GaramondNo8-MedIta.ttf \
		GaramondNo8-Reg.ttf \
		LetterGothic-Bol.ttf \
		LetterGothic-Ita.ttf \
		LetterGothic-Reg.ttf \
		Mauritius-Reg.ttf \
		NimbusMono-Bol.ttf \
		NimbusMono-BolIta.ttf \
		NimbusMono-Ita.ttf \
		NimbusMono-Reg.ttf \
		NimbusRomanNo4-Bol.ttf \
		NimbusRomanNo4-BolIta.ttf \
		NimbusRomanNo4-Lig.ttf \
		NimbusRomanNo4-LigIta.ttf \
		U001-Bol.ttf \
		U001-BolIta.ttf \
		U001-Ita.ttf \
		U001-Reg.ttf \
		U001Con-Bol.ttf \
		U001Con-BolIta.ttf \
		U001Con-Ita.ttf \
		U001Con-Reg.ttf \
		URWClassico-Bol.ttf \
		URWClassico-BolIta.ttf \
		URWClassico-Ita.ttf \
		URWClassico-Reg.ttf
EXTRAFONTDIR=	${WRKDIR}/urwfonts-1.41
EXTRAFONT=	LetterGothic-BolIta.ttf
INSTALL_DOCS=	COPYING.AFPL


USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for fontfile in ${EXTRAFONT}
	${INSTALL_DATA} ${EXTRAFONTDIR}/${fontfile} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor
.include "../../mk/bsd.pkg.mk"
