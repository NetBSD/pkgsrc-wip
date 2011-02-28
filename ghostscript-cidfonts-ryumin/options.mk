# $NetBSD: options.mk,v 1.3 2011/02/28 08:05:25 makoto Exp $

# gcr = ghostscript-cidfonts-ryumin
PKG_OPTIONS_VAR=        PKG_OPTIONS.gcr_type
PKG_SUPPORTED_OPTIONS=  ipa adobe-cidfonts umefont motoya
PKG_SUGGESTED_OPTIONS=  ipa

PLIST_VARS+=	cidfmap
PLIST_VARS+=	adobe

.include "../../mk/bsd.options.mk"

# -------- Adobe CID font requested -------------
.if !empty(PKG_OPTIONS:Madobe-cidfonts)
DEPENDS+=	adobe-cidfonts:../../fonts/adobe-cidfonts
DEPENDS+=	ghostscript-cidfonts:../../fonts/ghostscript-cidfonts
GCR_INSTALL_TYPE= adobe
.endif

# -------- motoya-fonts (TTF) requested -------------
.if !empty(PKG_OPTIONS:Mmotoya)
GS_CIDFMAP=	cidfmap-motoya
DEPENDS+=	ipafont:../../fonts/motoya-fonts
PLIST.cidfmap=	yes
GCR_INSTALL_TYPE= ttf
.endif

# -------- umefont (TTF) requested -------------
.if !empty(PKG_OPTIONS:Mumefont)
GS_CIDFMAP=	cidfmap-umefont
DEPENDS+=	ipafont:../../fonts/umefont-ttf
PLIST.cidfmap=	yes
GCR_INSTALL_TYPE= ttf
.endif

# -------- IPA (TTF) font requested -------------
.if !empty(PKG_OPTIONS:Mipa)
GS_CIDFMAP=	cidfmap-ipa
DEPENDS+=	ipafont:../../fonts/ipafont
PLIST.cidfmap=	yes
GCR_INSTALL_TYPE= ttf
.endif

# fonts/ja-sazanami-ttf/DESCR:Free Japanese TrueType font based on Wada lab. font (CLWFK) and
# fonts/kochi-ttf/DESCR:Kochi-gothic is a free Japanese TrueType font developed by Yasuyuki Furukawa.
# fonts/monafonts-ttf/DESCR:Japanese Windows font. This is named after ascii art 'mona' used in
# fonts/motoya-fonts/DESCR:Motoya fonts for Android handset display.
# fonts/umefont-ttf/DESCR:This package contains 18 Japanese fonts of Umefont family.
# fonts/vlgothic-ttf/DESCR:Japanese TrueType font using by Vine Linux.
