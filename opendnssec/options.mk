# $NetBSD: options.mk,v 1.3 2009/10/24 21:33:59 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		auditor softhsm
PKG_SUGGESTED_OPTIONS=		auditor

.include "../../mk/bsd.options.mk"

###
### Kasp Auditor
###
.if empty(PKG_OPTIONS:Mauditor)
CONFIGURE_ARGS+=	--disable-auditor
.else
.include "../../lang/ruby/buildlink3.mk"

DEPENDS+=	rubygems:../../misc/rubygems
DEPENDS+=	${RUBY_PKGPREFIX}-dnsruby>=1.39:../../wip/ruby-dnsruby
.endif

###
### SoftHSM
###
.if empty(PKG_OPTIONS:Msofthsm)

.else

#DEPENDS+=	softhsm:../../wip/softhsm
.include "../../wip/softhsm/buildlink3.mk"
.endif
