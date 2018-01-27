# $NetBSD: options.mk,v 1.1.1.1 2011/07/12 09:18:11 phonohawk Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.hs-cairo

PKG_SUPPORTED_OPTIONS= \
	pdf \
	ps \
	svg

PKG_SUGGESTED_OPTIONS= \
	pdf \
	ps \
	svg

.include "../../mk/bsd.options.mk"

# Enable the PDF backend of Cairo.
.if !empty(PKG_OPTIONS:Mpdf)
CONFIGURE_ARGS+=	-fcairo_pdf
.else
CONFIGURE_ARGS+=	-f-cairo_pdf
.endif

# Enable the PostScript backend of Cairo.
.if !empty(PKG_OPTIONS:Mps)
CONFIGURE_ARGS+=	-fcairo_ps
.else
CONFIGURE_ARGS+=	-f-cairo_ps
.endif

# Enable the Scalable Vector Graphics (SVG) backend of Cairo.
.if !empty(PKG_OPTIONS:Msvg)
CONFIGURE_ARGS+=	-fcairo_svg
.else
CONFIGURE_ARGS+=	-f-cairo_svg
.endif
