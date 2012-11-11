# $NetBSD: buildlink3.mk,v 1.14 2012/11/11 13:44:12 othyro Exp $

BUILDLINK_TREE+=	xmms2

.if !defined(XMMS2_BUILDLINK3_MK)
XMMS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmms2+=	xmms2>=0.8

pkgbase := xmms2
.include "../../mk/pkg-build-options.mk"


.if !empty(PKG_BUILD_OPTIONS.xmms2:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mboost)
.include "../../devel/boost-headers/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mcurl)
.include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mecore)
.include "../../devel/ecore/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mfaad)
.include "../../audio/faad2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mffmpeg)
.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mfftw)
.include "../../math/fftwf/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mflac)
.include "../../audio/flac/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mgnomevfs)
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mlibao)
.include "../../audio/libao/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mlibcdio)
.include "../../misc/libcdio/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mlibdiscid)
.include "../../audio/libdiscid/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mlibgme)
.include "../../wip/libgme/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mlibmms)
.include "../../net/libmms/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mlibmpg123)
.include "../../wip/libmpg123/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mlibofa)
.include "../../audio/libofa/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mlibvisual)
.include "../../audio/libvisual/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mmad)
.include "../../audio/libmad/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mmodplug)
.include "../../audio/libmodplug/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mmpcdec)
.include "../../audio/libmpcdec/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mperl)
.include "../../lang/perl5/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mpython)
.include "../../devel/py-cython/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mruby)
.include "../../lang/ruby/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mreadline)
.include "../../devel/readline/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Msamba)
.include "../../net/samba/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mshout)
.include "../../audio/libshout/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Msidplay)
.include "../../audio/libsidplay2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Msndfile)
.include "../../audio/libsndfile/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mspeex)
.include "../../audio/speex/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mtremor)
.include "../../audio/tremor/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.xmms2:Mwavpack)
.include "../../audio/wavpack/buildlink3.mk"
.endif


.include "../../devel/SDL/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # XMMS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmms2
