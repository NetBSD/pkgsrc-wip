# $NetBSD: options.mk,v 1.1.1.1 2011/02/23 13:40:10 makoto Exp $

# gcr = ghostscript-cidfonts-ryumin
PKG_OPTIONS_VAR=        PKG_OPTIONS.gcr_type
PKG_SUPPORTED_OPTIONS=  ipa adobe-cidfonts
PKG_SUGGESTED_OPTIONS=  ipa

PLIST_VARS+=	cidfmap
PLIST_VARS+=	adobe

.include "../../mk/bsd.options.mk"

# Following now seems just to switch adobe-cidfonts ->adobe, ipa -> ttf
# But there may be chance to another TTF font -> ttf

# -------- Adobe CID font requested -------------
.if !empty(PKG_OPTIONS:Madobe-cidfonts)
DEPENDS+=	adobe-cidfonts:../../fonts/adobe-cidfonts
DEPENDS+=	ghostscript-cidfonts:../../fonts/ghostscript-cidfonts
GCR_INSTALL_TYPE= adobe
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
# fonts/umefont-ttf/DESCR:This package contains 18 Japanese fonts of Umefont family.
# fonts/vlgothic-ttf/DESCR:Japanese TrueType font using by Vine Linux.
