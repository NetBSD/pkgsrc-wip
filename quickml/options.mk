# $NetBSD: options.mk,v 1.3 2011/05/08 02:59:17 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.quickml
PKG_SUPPORTED_OPTIONS+= limit analog


.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Mlimit)
LIMIT_PATCH=	quickml-0.7-limited.patch
PATCHFILES+=	${LIMIT_PATCH}
#SITES.${LIMIT_PATCH}=	http://linux.matchy.net/view.xcg?c=plugin;plugin=attach_download;p=QuickMLLimited;file_name=
SITES.${LIMIT_PATCH}=	http://matchy.s28.xrea.com/hiki.xcg?c=plugin;plugin=attach_download;p=QuickMLLimited;file_name=
PATCH_DIST_STRIP.${LIMIT_PATCH}=	-p1
.endif


.if !empty(PKG_OPTIONS:Manalog)
USE_TOOLS+=	gs:run
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot
.endif
