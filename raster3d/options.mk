# $NetBSD: options.mk,v 1.1.1.1 2010/06/01 06:32:38 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.raster3d
PKG_SUPPORTED_OPTIONS=	magick
PKG_SUGGESTED_OPTIONS=	magick

.include "../../mk/bsd.options.mk"
