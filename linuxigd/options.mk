# $NetBSD: options.mk,v 1.2 2005/04/21 13:08:51 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.linuxigd
PKG_SUPPORTED_OPTIONS=	iptables pf ipfilter

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_DEFAULT_OPTIONS=	iptables
.elif ${OPSYS} == "OpenBSD"
PKG_DEFAULT_OPTIONS=	pf
.else
PKG_DEFAULT_OPTIONS=	ipfilter
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Miptables)
CFLAGS+=	-DFILTER_CMD="iptables"
.elif !empty(PKG_OPTIONS:Mpf)
CFLAGS+=	-DFILTER_CMD="pf"
.elif !empty(PKG_OPTIONS:Mipfilter)
CFLAGS+=	-DFILTER_CMD="ipfilter"
.else
PKG_FAIL_REASON+=	"${PKG_OPTIONS_VAR} must contaion one of" \
			"\"iptables\" or \"pf\" or \"ipfilter\"!"
.endif
