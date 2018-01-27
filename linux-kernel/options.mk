# $NetBSD: options.mk,v 1.2 2008/05/24 15:34:11 tnn2 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.linux-kernel
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"
