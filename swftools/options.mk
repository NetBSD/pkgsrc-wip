# $NetBSD: options.mk,v 1.6 2014/10/02 09:31:55 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.swftools
PKG_SUPPORTED_OPTIONS=	lame pdf

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pdf

.if !empty(PKG_OPTIONS:Mlame)
CONFIGURE_ARGS+=	--enable-lame
BUILDLINK_INCDIRS.lame=	include/lame
.include "../../audio/lame/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-lame
.endif

.if !empty(PKG_OPTIONS:Mpdf)
.include "../../print/pdflib-lite/buildlink3.mk"
PLIST.pdf=	yes
.else
CONFIGURE_ENV+=		DISABLEPDF2PDF=true
.endif
