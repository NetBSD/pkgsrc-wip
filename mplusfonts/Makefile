# $NetBSD: Makefile,v 1.2 2003/11/28 08:29:44 jeremy-c-reed Exp $
# FreeBSD Id: ports/japanese/mplusfonts/Makefile,v 1.2 2003/01/15 14:42:22 nobutaka Exp

DISTNAME=	mplus_fonts_J-1.0.4
PKGNAME=	mplusfonts-1.0.4
CATEGORIES=	fonts japanese
MASTER_SITES=	http://downloads.sourceforge.jp/mplus-fonts/2050/ \
		http://wids.net/archive/mplusfonts/distfiles/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mplus-fonts.sourceforge.jp/
COMMENT=	12x13 dots X11 kanji fonts with simple and readable design

USE_X11BASE=	yes
PLIST_SUBST+=	FONTDIR=${FONTDIR}

FONTS=	mplus_j12b mplus_j12b_iso8859 mplus_j12b_jisx0201 \
	mplus_j12r mplus_j12r_iso8859 mplus_j12r_jisx0201
FONTDIR=	${PREFIX}/lib/X11/fonts/local

do-build:
	@cd ${WRKSRC};                                          \
	for FONT in ${FONTS}; do                                \
	  ${ECHO} -n "Compiling font $${FONT} ... ";            \
	  ${X11BASE}/bin/bdftopcf $${FONT}.bdf |                \
	    ${GZIP_CMD} -c >$${FONT}.pcf.gz;                    \
	  ${ECHO} "done";                                       \
	done

pre-install:
	[ -d ${FONTDIR} ] || ${INSTALL_DATA_DIR} ${FONTDIR}

do-install:
	@for FONT in ${FONTS}; do                               \
	  ${ECHO} -n "Installing font $${FONT} ... ";           \
	  ${INSTALL_DATA} ${WRKSRC}/$${FONT}.pcf.gz             \
	    ${FONTDIR};                                         \
	  ${ECHO} "done";                                       \
	done
	@cd ${FONTDIR}; ${X11BASE}/bin/mkfontdir

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mplusfonts
	${INSTALL_DATA} ${WRKSRC}/LICENSE \
		${PREFIX}/share/doc/mplusfonts
	${INSTALL_DATA} ${WRKSRC}/README_J \
		${PREFIX}/share/doc/mplusfonts

.include "../../mk/bsd.pkg.mk"
