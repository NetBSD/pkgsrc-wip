# $NetBSD: options.mk,v 1.6 2015/03/27 11:14:09 athaba Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tor
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS+=	doc

.include "../../mk/bsd.options.mk"

###
### This enables the build of manual pages. It requires asciidoc
### at build time, which comes with a tail of dependencies and
### may not be wanted under certain circumstances.
###
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		asciidoc>=8.3.3:../../textproc/asciidoc
CONFIGURE_ARGS+=	--enable-asciidoc
.else
CONFIGURE_ARGS+=	--disable-asciidoc
.endif
