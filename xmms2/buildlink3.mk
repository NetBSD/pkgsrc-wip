# $NetBSD: buildlink3.mk,v 1.13 2012/11/05 00:42:28 othyro Exp $

BUILDLINK_TREE+=	xmms2

.if !defined(XMMS2_BUILDLINK3_MK)
XMMS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmms2+=	xmms2>=0.8

pkgbase := xmms2
.include "../../mk/pkg-build-options.mk"


.if !empty(PKG_BUILD_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mboost)
.include "../../devel/boost-headers/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mecore)
.include "../../devel/ecore/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mfaad)
.include "../../audio/faad2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mfftw)
.include "../../math/fftwf/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mflac)
.include "../../audio/flac/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mgnomevfs)
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mlibao)
.include "../../audio/libao/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mlibcdio)
.include "../../misc/libcdio/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mlibdiscid)
.include "../../audio/libdiscid/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mlibgme)
.include "../../wip/libgme/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mlibmms)
.include "../../net/libmms/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mlibmpg123)
.include "../../wip/libmpg123/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mlibofa)
.include "../../audio/libofa/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mlibvisual)
.include "../../audio/libvisual/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mmad)
.include "../../audio/libmad/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mmodplug)
.include "../../audio/libmodplug/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mmpcdec)
.include "../../audio/libmpcdec/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mperl)
.include "../../lang/perl5/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mpython)
.include "../../devel/py-cython/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mruby)
.include "../../lang/ruby/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Msamba)
.include "../../net/samba/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mshout)
.include "../../audio/libshout/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Msidplay)
.include "../../audio/libsidplay2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Msndfile)
.include "../../audio/libsndfile/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mspeex)
.include "../../audio/speex/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mtremor)
.include "../../audio/tremor/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mwavpack)
.include "../../audio/wavpack/buildlink3.mk"
.endif


.include "../../devel/SDL/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # XMMS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmms2
