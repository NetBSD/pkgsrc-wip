# $NetBSD: options.mk,v 1.1 2007/11/14 23:24:01 hoka_adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.linux-kernel
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"                                                
