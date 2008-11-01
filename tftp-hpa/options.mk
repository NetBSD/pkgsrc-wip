# $NetBSD: options.mk,v 1.2 2008/11/01 07:37:45 gschwarz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tftp-hpa
PKG_SUPPORTED_OPTIONS=	tcpwrappers remap inet6
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

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif
