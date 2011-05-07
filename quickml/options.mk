# $NetBSD: options.mk,v 1.1.1.1 2011/05/07 07:27:21 makoto Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.quickml
PKG_SUPPORTED_OPTIONS+= limit analog


.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Mlimit)
LIMIT_PATCH=  quickml-0.7-limited.patch
PATCHFILES+=            ${LIMIT_PATCH}
#SITES.${LIMIT_PATCH}=        http://linux.matchy.net/view.xcg?c=plugin;plugin=attach_download;p=QuickMLLimited;file_name=
SITES.${LIMIT_PATCH}=        http://matchy.s28.xrea.com/hiki.xcg?c=plugin;plugin=attach_download;p=QuickMLLimited;file_name=
PATCH_DIST_STRIP.${LIMIT_PATCH}=     -p1
.endif


.if !empty(PKG_OPTIONS:Manalog)
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
DEPENDS+=      gnuplot>=3.7:../../graphics/gnuplot
.endif
