# $NetBSD$
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.qtractor
PKG_SUPPORTED_OPTIONS=		mad vorbis samplerate
PKG_SUPPORTED_OPTIONS+=		lilv lv2 # new options
PKG_SUPPORTED_OPTIONS+=		dssi liblo rubberband # pkgsrc-wip
PKG_SUGGESTED_OPTIONS=		mad vorbis samplerate

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mad vorbis samplerate ddi liblo

.if !empty(PKG_OPTIONS:Mlv2)
.include "../../audio/lv2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlilv)
.include "../../audio/lilv/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmad)
.include "../../audio/libmad/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdssi)
.include "../../wip/dssi/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mliblo)
.include "../../wip/liblo/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrubberband)
.include "../../wip/rubberband/buildlink3.mk"
.endif
