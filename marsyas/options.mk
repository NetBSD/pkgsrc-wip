PKG_OPTIONS_VAR=	PKG_OPTIONS.marsyas
PKG_SUPPORTED_OPTIONS=	mad vorbis
PKG_SUGGESTED_OPTIONS=	mad

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmad)
#
.  include "../../audio/libmad/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mad=${BUILDLINK_PREFIX.libmad}
.else
CONFIGURE_ARGS+=	--without-mad
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
#
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--with-vorbis=${BUILDLINK_PREFIX.libvorbis}
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif
