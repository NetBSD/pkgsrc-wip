# $NetBSD: options.mk,v 1.5 2012/07/28 17:29:28 gregoire Exp $
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

UNIFONT=		unifont-5.1.20080820.pcf
SITES.${UNIFONT}.gz=	http://unifoundry.com/

post-extract: do-move-unifont
.PHONY: do-move-unifont

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-mm-debug
.else
CONFIGURE_ARGS+=	--disable-mm-debug
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--enable-grub-mkfont
PLIST.freetype=		yes
DISTFILES+=		${UNIFONT}.gz
TOOL_DEPENDS+=		dejavu-ttf>=2.30:../../fonts/dejavu-ttf
do-move-unifont:
	${MV} ${WRKDIR}/${UNIFONT} ${WRKSRC}/unifont.pcf
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-grub-mkfont
do-move-unifont:
.endif
