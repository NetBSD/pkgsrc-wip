PKG_OPTIONS_VAR=	PKG_OPTIONS.jack
PKG_SUPPORTED_OPTIONS=	portaudio sndfile
PKG_SUGGESTED_OPTIONS=	sndfile

.include "../../mk/bsd.fast.prefs.mk"

PKG_OPTIONS_OPTIONAL_GROUPS=	${MACHINE_ARCH}

PKG_OPTIONS_GROUP.powerpc= 	altivec
PKG_OPTIONS_GROUP.i386= 	simd


.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mportaudio)
.  include "../../audio/portaudio-devel/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-portaudio
.endif

.if !empty(PKG_OPTIONS:Msndfile)
PLIST_SUBST+=	LIBSNDFILE=""
.  include "../../audio/libsndfile/buildlink3.mk"
.else
PLIST_SUBST+=	LIBSNDFILE="@comment "
.endif

.if !empty(PKG_OPTIONS:Msimd)
CONFIGURE_ARGS+=	--enable-dynsimd
.else
CONFIGURE_ARGS+=	--disable-dynsimd
CONFIGURE_ARGS+=	--disable-mmx
CONFIGURE_ARGS+=	--disable-sse
.endif

.if !empty(PKG_OPTIONS:Maltivec)
CONFIGURE_ARGS+=	--enable-altivec
.else
CONFIGURE_ARGS+=	--disable-altivec
.endif
