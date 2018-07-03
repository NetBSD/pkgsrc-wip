# $NetBSD: options.mk,v 1.18 2014/10/23 09:23:36 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmms2
PKG_SUPPORTED_OPTIONS=	alsa avahi boost curl ecore faad ffmpeg flac fftw gamin
PKG_SUPPORTED_OPTIONS+=	gnomevfs jack libao libcdio libdiscid libgme libmms
PKG_SUPPORTED_OPTIONS+=	libmpg123 libofa libvisual mad modplug musepack pyrex ruby
PKG_SUPPORTED_OPTIONS+=	pulseaudio python readline samba shout sidplay
PKG_SUPPORTED_OPTIONS+=	sndfile speex tremor valgrind vorbis wavpack
PKG_SUGGESTED_OPTIONS=	curl flac mad vorbis

#PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS:S/ruby//1:S/gamin//1:S/samba//1:S/valgrind//1:S/alsa//1} # for testing

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS:S/libcdio//1:S/libdiscid//} cdda

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
#PLIST.alsa=		yes
.else
WITHOUT_PLUGINS+=	alsa
.endif

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
PLIST.avahi=		yes
.else
WITHOUT_PLUGINS+=	avahi
.endif

.if !empty(PKG_OPTIONS:Mboost)
.include "../../devel/boost-headers/buildlink3.mk"
BOOST_INCLUDES=		${BUILDLINK_PREFIX.boost-headers}/include/boost
#PLIST.boost=		yes
.else
WITHOUT_PLUGINS+=	boost
BOOST_INCLUDES=		/dev/null
.endif

.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
PLIST.curl=		yes
.else
WITHOUT_PLUGINS+=	curl
.endif

.if !empty(PKG_OPTIONS:Mecore)
.include "../../devel/ecore/buildlink3.mk"
PLIST.ecore=		yes
.else
WITHOUT_PLUGINS+=	ecore
.endif

.if !empty(PKG_OPTIONS:Mfaad)
.include "../../audio/faad2/buildlink3.mk"
PLIST.faad=		yes
.else
WITHOUT_PLUGINS+=	faad
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg1/buildlink3.mk"
CFLAGS+=		${BUILDLINK_PREFIX.ffmpeg}/include
PLIST.ffmpeg=		yes
.else
WITHOUT_PLUGINS+=	avcodec
.endif

.if !empty(PKG_OPTIONS:Mfftw)
.include "../../math/fftwf/buildlink3.mk"
#PLIST.fftw=		yes
.else
WITHOUT_PLUGINS+=	fftw3f
.endif

.if !empty(PKG_OPTIONS:Mflac)
.include "../../audio/flac/buildlink3.mk"
PLIST.flac=		yes
.else
WITHOUT_PLUGINS+=	flac
.endif

.if !empty(PKG_OPTIONS:Mgamin)
BUILD_DEPENDS+=		gamin-[0-9]*:../../sysutils/gamin
PLIST.gamin=		yes
.else
WITHOUT_PLUGINS+=	gamin
.endif

.if !empty(PKG_OPTIONS:Mgnomevfs)
.include "../../sysutils/gnome-vfs/buildlink3.mk"
PLIST.gnomevfs=		yes
.else
WITHOUT_PLUGINS+=	gnomevfs
.endif

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
PLIST.jack=		yes
.else
WITHOUT_PLUGINS+=	jack
.endif

.if !empty(PKG_OPTIONS:Mlibao)
.include "../../audio/libao/buildlink3.mk"
PLIST.libao=		yes
.else
WITHOUT_PLUGINS+=	ao
.endif

.if !empty(PKG_OPTIONS:Mlibcdio)
.include "../../misc/libcdio/buildlink3.mk"
PLIST.cdda=		yes
.else
WITHOUT_PLUGINS+=	cdda
.endif

.if !empty(PKG_OPTIONS:Mlibdiscid)
.include "../../audio/libdiscid/buildlink3.mk"
PLIST.cdda=		yes
.else
WITHOUT_PLUGINS+=	cdda
.endif

.if !empty(PKG_OPTIONS:Mlibgme)
.include "../../wip/libgme/buildlink3.mk"
PLIST.libgme=		yes
.else
WITHOUT_PLUGINS+=	gme
.endif

.if !empty(PKG_OPTIONS:Mlibmms)
.include "../../net/libmms/buildlink3.mk"
PLIST.libmms=		yes
.else
WITHOUT_PLUGINS+=	mms
.endif

.if !empty(PKG_OPTIONS:Mlibmpg123)
BUILD_DEPENDS+=	libmpg123>=1.5.1:../../wip/libmpg123
.include "../../wip/libmpg123/buildlink3.mk"
PLIST.libmpg123=	yes
.else
WITHOUT_PLUGINS+=	mpg123
.endif

.if !empty(PKG_OPTIONS:Mlibofa)
.include "../../audio/libofa/buildlink3.mk"
PLIST.libofa=		yes
.else
WITHOUT_PLUGINS+=	ofa
.endif

.if !empty(PKG_OPTIONS:Mlibvisual)
.include "../../audio/libvisual/buildlink3.mk"
#PLIST.libvisual=	yes
.else
#WITHOUT_PLUGINS+=	# ?
.endif

.if !empty(PKG_OPTIONS:Mmad)
.include "../../audio/libmad/buildlink3.mk"
PLIST.mad=		yes
.else
WITHOUT_PLUGINS+=	mad
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
.include "../../audio/libmodplug/buildlink3.mk"
PLIST.modplug=		yes
.else
WITHOUT_PLUGINS+=	modplug
.endif

.if !empty(PKG_OPTIONS:Mmusepack)
.include "../../audio/musepack/buildlink3.mk"
PLIST.musepack=		yes
.else
WITHOUT_PLUGINS+=	musepack
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
PLIST.pulseaudio=	yes
.else
WITHOUT_PLUGINS+=	pulse
.endif

.if !empty(PKG_OPTIONS:Mpyrex)
BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-pyrex
.include "../../lang/python/extension.mk"
PY_PATCHPLIST=		yes
PLIST.pyrex=		yes
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../devel/py-cython/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mruby)
USE_RUBY_DIST_SUBDIR=	no
.include "../../lang/ruby/buildlink3.mk"
PLIST.ruby=		yes
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
PLIST.readline=		yes
.else
WITHOUT_PLUGINS+=	nycli
.endif

.if !empty(PKG_OPTIONS:Msamba)
.include "../../net/samba/buildlink3.mk"
#PLIST.samba=		yes
.else
WITHOUT_PLUGINS+=	samba
.endif

.if !empty(PKG_OPTIONS:Mshout)
.include "../../audio/libshout/buildlink3.mk"
PLIST.shout=		yes
.else
WITHOUT_PLUGINS+=	ices
.endif

# this is currently disabled by the package itself.
.if !empty(PKG_OPTIONS:Msidplay)
.include "../../audio/libsidplay2/buildlink3.mk"
EXTRA_INCLUDES+=	${BUILDLINK_PREFIX.libsidplay2}/include/libsidplay2
PLIST.sidplay=		yes
.else
WITHOUT_PLUGINS+=	sid
.endif

.if !empty(PKG_OPTIONS:Msndfile)
.include "../../audio/libsndfile/buildlink3.mk"
PLIST.sndfile=		yes
.else
WITHOUT_PLUGINS+=	sndfile
.endif

.if !empty(PKG_OPTIONS:Mspeex)
.include "../../audio/speex/buildlink3.mk"
PLIST.speex=		yes
.else
WITHOUT_PLUGINS+=	speex
.endif

.if !empty(PKG_OPTIONS:Mtremor)
.include "../../audio/tremor/buildlink3.mk"
PLIST.tremor=		yes
.else
WITHOUT_PLUGINS+=	tremor
.endif

.if !empty(PKG_OPTIONS:Mvalgrind)
BUILD_DEPENDS+=		valgrind-[0-9]*:../../devel/valgrind
#PLIST.valgrind=	yes
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
PLIST.vorbis=		yes
.else
WITHOUT_PLUGINS+=	vorbis vorbis_common
.endif

.if !empty(PKG_OPTIONS:Mwavpack)
.include "../../audio/wavpack/buildlink3.mk"
PLIST.wavpack=		yes
.else
WITHOUT_PLUGINS+=	wavpack
.endif
