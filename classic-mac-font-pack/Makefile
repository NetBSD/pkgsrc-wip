# $NetBSD: Makefile,v 1.5 2010/03/04 21:12:27 christtrekker Exp $
#

DISTNAME=	classic-mac-font-pack-0.1
CATEGORIES=	fonts

# Included fonts (or homages/reproductions) are the "city" fonts (Athens,
# Cairo, Chicago, Geneva, London, Los Angeles, Monaco, New York, San
# Francisco, Toronto, Venice), Apple Garamond, Charcoal, and Motter Tektura.
# This package will hit 1.0 when all of these, or reasonable facsimiles,
# are available gratis.

DISTFILES+=	alexandria.zip
SITES.alexandria.zip=	http://www.acidfonts.com/fonts/
# defunct	http://www.1001freefonts.com/winfonts/
DISTFILES+=	Cairo_TTF.zip
SITES.Cairo_TTF.zip=	http://www.masterstech-home.com/The_Library/Font_Samples/Font_Sample_Files/PC/C/
# File is invalid?
#DISTFILES+=	Chicago_TTF.zip
#SITES.Chicago_TTF.zip=	http://www.masterstech-home.com/The_Library/Font_Samples/Font_Sample_Files/PC/C/
#DISTFILES+=	CHICAGO.ttf
#SITES.CHICAGO.ttf=	http://www.fontyukle.com/en/
DISTFILES+=	Geneva_TTF.zip
SITES.Geneva_TTF.zip=	http://www.masterstech-home.com/The_Library/Font_Samples/Font_Sample_Files/PC/G/
DISTFILES+=	London.ttf.gz
SITES.London.ttf.gz=	http://68kmla.net/wiki/uploads/4/4a/
DISTFILES+=	CityOfAngelsTTF.zip
SITES.CityOfAngelsTTF.zip=	http://68kmla.net/wiki/uploads/0/0a/
DISTFILES+=	MONACO.TTF
SITES.MONACO.TTF=	http://www.webdevkungfu.com/files/
# Cf. http://www.gringod.com/wp-upload/software/Fonts/Monaco_5.1.ttf
# Cf. http://www.gringod.com/wp-upload/software/Fonts/Monaco_Linux.ttf
# This binhex file yields a StuffIt archive, which there is no practical way
# to extract in the general case.
#DISTFILES+=	NewYork_TT.hqx
#SITES.NewYork_TT.hqx=	http://www.masterstech-home.com/The_Library/Font_Samples/Font_Sample_Files/Mac/N/
# bmake doesn't like this filename??
#DISTFILES+=	Fernando%20Regular%20(2).ttf
#SITES.Fernando%20Regular%20(2).ttf=	http://ufonts.com/bin/
# Brampton is not yet complete.
DISTFILES+=	Brampton.tgz
SITES.Brampton.tgz=	http://christtrek.dyndns.org:8000/fnt/
DISTFILES+=	genoa.zip
SITES.genoa.zip=	http://www.searchfreefonts.com/assets/downloads/

# This next one has Apple Garamond.
# I don't think it is freely distributable though.
DISTFILES+=	macfonts.tar.gz
SITES.macfonts.tar.gz=	http://ubuntu-debs.googlecode.com/files/
DISTFILES+=	virtue.zip
SITES.virtue.zip=	http://www.scootergraphics.com/virtue/
DISTFILES+=	Mottek.zip
SITES.Mottek.zip=	http://www.searchfreefonts.com/assets/downloads/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://68kmla.net/wiki/User:ChristTrekker/Choosing_Mac_fonts_for_the_web
COMMENT=	Outline fonts modeled after those of the vintage 68k Macintosh era
LICENSE=	generic-nonlicense
RESTRICTED=	Various.

WRKSRC=		${WRKDIR}
TTFPATH=	lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH}
INSTALLATION_DIRS=	${TTFPATH}
NO_CONFIGURE=	yes
NO_BUILD=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

# OPTIONS
PKG_OPTIONS_VAR=	PKG_OPTIONS.classic-mac-font-pack
PKG_SUPPORTED_OPTIONS=	agaramond

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_VARS+=	agaramond
.if !empty(PKG_OPTIONS:Magaramond)
PLIST.agaramond=	yes
.endif

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/brampton/Brampton.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	if [ "x${PLIST.agaramond}" = "xyes" ]; then \
		${INSTALL_DATA} ${WRKSRC}/macfonts/AppleGaramond*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf}; \
	fi
# install doco too!

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
