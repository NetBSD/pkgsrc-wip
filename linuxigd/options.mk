# $NetBSD: options.mk,v 1.4 2005/05/31 10:02:12 dillo Exp $

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
CFLAGS+=	-DFILTER_CMD="iptables"
.elif !empty(PKG_OPTIONS:Mpf)
CFLAGS+=	-DFILTER_CMD="pf"
MESSAGE_SRC+=	${.CURDIR}/MESSAGE.pf
.elif !empty(PKG_OPTIONS:Mipfilter)
CFLAGS+=	-DFILTER_CMD="ipfilter"
.else
PKG_FAIL_REASON+=	"${PKG_OPTIONS_VAR} must contaion one of" \
			"\"iptables\" or \"pf\" or \"ipfilter\"!"
.endif
