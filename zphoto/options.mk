# $NetBSD: options.mk,v 1.2 2005/05/31 10:02:14 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.zphoto
PKG_SUPPORTED_OPTIONS=	imlib2 magick zip avifile wx
PKG_SUGGESTED_OPTIONS=	imlib2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mimlib2)
.  include "../../graphics/imlib2/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-magick
.elif !empty(PKG_OPTIONS:Mmagick)
.  include "../../graphics/ImageMagick/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-imlib2
.else
PKG_FAIL_REASON+=	"${PKG_OPTIONS_VAR} must contaion one of" \
			"\"imlib2\" or \"magick\"!"
.endif

.if !empty(PKG_OPTIONS:Mzip)
DEPENDS+=	zip-[0-9]*:../../archivers/zip
.else
CONFIGURE_ARGS+=	--disable-zip
.endif

.if !empty(PKG_OPTIONS:Mavifile)
.include "../../wip/avifile-devel/buildlink3.mk"
BUILDLINK_DEPENDS.avifile-deveL+=	avifile-devel>=0.7.34
.else
CONFIGURE_ARGS+=	--disable-avifile
.endif

.if !empty(PKG_OPTIONS:Mwx)
.include "../../x11/wxGTK/buildlink3.mk"
PLIST_SUBST+=		WX_COMMENT=
.else
CONFIGURE_ARGS+=	--disable-wx
PLIST_SUBST+=		WX_COMMENT="@comment "
.endif
