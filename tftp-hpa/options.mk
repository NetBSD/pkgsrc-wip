# $NetBSD: options.mk,v 1.1.1.1 2007/01/01 18:40:20 gschwarz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tftp-hpa
PKG_SUPPORTED_OPTIONS=	tcpwrappers remap
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtcpwrappers)
.include "../../security/tcp_wrappers/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-tcpwrappers
.endif

.if empty(PKG_OPTIONS:Mremap)
CONFIGURE_ARGS+=	--without-remap
.endif
