# $NetBSD: options.mk,v 1.2 2014/11/24 16:27:03 thomasklausner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libsocialweb
PKG_SUPPORTED_OPTIONS+=		facebook flickr lastfm photobucket plurk smugmug
PKG_SUPPORTED_OPTIONS+=		twitter vimeo youtube sina myspace
#PKG_SUPPORTED_OPTIONS+=	vala	# XXX broken

PKG_SUGGESTED_OPTIONS+=		facebook flickr lastfm photobucket plurk smugmug
PKG_SUGGESTED_OPTIONS+=		twitter vimeo youtube sina myspace

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

###
### services
###

.if !empty(PKG_OPTIONS:Mfacebook)
CONFIGURE_ARGS+=	--enable-facebook
PLIST.facebook=		yes
.endif

.if !empty(PKG_OPTIONS:Mflickr)
CONFIGURE_ARGS+=	--enable-flickr
PLIST.flickr=		yes
.endif

.if !empty(PKG_OPTIONS:Mlastfm)
CONFIGURE_ARGS+=	--enable-lastfm
PLIST.lastfm=		yes
.endif

.if !empty(PKG_OPTIONS:Mphotobucket)
CONFIGURE_ARGS+=	--enable-photobucket
PLIST.photobucket=	yes
.endif

.if !empty(PKG_OPTIONS:Mplurk)
CONFIGURE_ARGS+=	--enable-plurk
PLIST.plurk=		yes
.endif

.if !empty(PKG_OPTIONS:Msmugmug)
CONFIGURE_ARGS+=	--enable-smugmug
PLIST.smugmug=		yes
.endif

.if !empty(PKG_OPTIONS:Mtwitter)
CONFIGURE_ARGS+=	--enable-twitter
PLIST.twitter=		yes
.endif

.if !empty(PKG_OPTIONS:Mvimeo)
CONFIGURE_ARGS+=	--enable-vimeo
PLIST.vimeo=		yes
.endif

.if !empty(PKG_OPTIONS:Myoutube)
CONFIGURE_ARGS+=	--enable-youtube
PLIST.youtube=		yes
.endif

.if !empty(PKG_OPTIONS:Msina)
CONFIGURE_ARGS+=	--enable-sina
PLIST.sina=		yes
.endif

.if !empty(PKG_OPTIONS:Mmyspace)
CONFIGURE_ARGS+=	--enable-myspace
PLIST.myspace=		yes
.endif

### Vala	# XXX broke and needed for libfolks
# does not build with either vala 0.12, 0.14, 0.18,
# 0.20, nor 0.26

.if !empty(PKG_OPTIONS:Mvala)
CONFIGURE_ARGS=		--enable-introspection=yes
CONFIGURE_ARGS=		--enable-vala-bindings
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.endif
