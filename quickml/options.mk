# $NetBSD: options.mk,v 1.5 2011/05/19 12:36:38 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.quickml
PKG_SUPPORTED_OPTIONS+= quickml-limit analog

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	analog

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
PLIST.analog=	yes
.else
SUBST_CLASSES+=		analog
SUBST_STAGE.analog=	pre-configure
SUBST_MESSAGE.analog=	Disable quickml-analog script.
SUBST_FILES.analog=	Makefile.in
SUBST_SED.analog=	-e '/^bin_SCRIPTS =/s/quickml-analog//g'
.endif
