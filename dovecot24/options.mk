# $NetBSD: options.mk,v 1.14 2021/11/09 12:04:43 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dovecot24
PKG_SUPPORTED_OPTIONS=	kqueue pam tcpwrappers
PKG_SUGGESTED_OPTIONS=	pam tcpwrappers

.if defined(OPSYS_HAS_KQUEUE)
PKG_SUGGESTED_OPTIONS+=	kqueue
.endif
PLIST_VARS+=		tcpwrappers

.include "../../mk/bsd.options.mk"

###
### PAM support
###
.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-pam
.  include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pam
.endif

###
### kqueue support
###
.if !empty(PKG_OPTIONS:Mkqueue)
CONFIGURE_ARGS+=	--with-ioloop=kqueue
CONFIGURE_ARGS+=	--with-notify=kqueue
.else
# use the defaults
.endif

###
### tcpwrappers support
###
.if !empty(PKG_OPTIONS:Mtcpwrappers)
CONFIGURE_ARGS+=	--with-libwrap
.  include "../../security/tcp_wrappers/buildlink3.mk"
PLIST.tcpwrappers=	yes
.endif
