# $NetBSD: options.mk,v 1.4 2011/06/05 21:59:32 gregoire Exp $
#

#
# Description of options (taken from configure --help):
# debug			include memory manager debugging
# freetype		build and install the `grub-mkfont' utility
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.grub2
PKG_SUPPORTED_OPTIONS=	debug freetype
PKG_SUGGESTED_OPTIONS=	freetype

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		freetype

UNIFONT_URL=		http://unifoundry.com/unifont-5.1.20080820.pcf.gz
UNIFONT_EXT=		pcf.gz

post-extract: do-download-unifont
.PHONY: do-download-unifont

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-mm-debug
.else
CONFIGURE_ARGS+=	--disable-mm-debug
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--enable-grub-mkfont
PLIST.freetype=		yes
USE_TOOLS+=		ftp
do-download-unifont:
	cd ${WRKSRC} && ftp -o unifont.${UNIFONT_EXT} ${UNIFONT_URL}
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-grub-mkfont
do-download-unifont:
.endif
