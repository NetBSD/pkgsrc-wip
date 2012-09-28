# $NetBSD: options.mk,v 1.1 2012/09/28 18:50:22 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.djplay
PKG_SUPPORTED_OPTIONS=	audiofile cdparanoia id3 ladspa libxml2 mad mpeg3 nls
PKG_SUPPORTED_OPTIONS+=	swh tap
PKG_SUGGESTED_OPTIONS=	audiofile id3 ladspa libxml2 mad nls tap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maudiofile)
.include "../../audio/libaudiofile/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcdparanoia)
.include "../../audio/cdparanoia/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mid3)
.include "../../audio/id3lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mladspa)
.include "../../audio/ladspa/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibxml2)
.include "../../textproc/libxml2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmad)
.include "../../audio/libmad/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmpeg3)
.include "../../multimedia/libmpeg3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mpeg3includes=${BUILDLINK_PREFIX.libmpeg3}/include/mpeg3
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
LIBS+=			-lintl
USE_TOOLS+=		msgfmt msgmerge xgettext
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mswh)
#.include "../../wip/swh-plugins/buildlink3.mk"
# swh-plugins hasn't been packaged yet due to build failure
.endif

.if !empty(PKG_OPTIONS:Mtap)
.include "../../wip/tap-plugins/buildlink3.mk"
.endif
