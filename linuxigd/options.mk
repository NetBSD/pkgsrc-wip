# $NetBSD: options.mk,v 1.6 2006/02/26 12:40:21 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.linuxigd
PKG_SUPPORTED_OPTIONS=	iptables pf ipfilter

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=	iptables
.elif ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS=	pf
.else
PKG_SUGGESTED_OPTIONS=	ipfilter
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Miptables)
CFLAGS+=	-DUSE_IPTABLES
.elif !empty(PKG_OPTIONS:Mpf)
CFLAGS+=	-DUSE_PF
MESSAGE_SRC+=	${.CURDIR:Q}/MESSAGE.pf
.elif !empty(PKG_OPTIONS:Mipfilter)
CFLAGS+=	-DUSE_IPFILTER
.else
PKG_FAIL_REASON+=	"${PKG_OPTIONS_VAR} must contaion one of" \
			"\"iptables\" or \"pf\" or \"ipfilter\"!"
.endif
