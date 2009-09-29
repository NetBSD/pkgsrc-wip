# $NetBSD: options.mk,v 1.2 2009/09/29 21:54:44 pettai Exp $

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
DEPENDS+=	${RUBY_PKGPREFIX}-dnsruby:../../wip/ruby-dnsruby
.endif

###
### SoftHSM
###
.if empty(PKG_OPTIONS:Msofthsm)

.else

#DEPENDS+=	softhsm:../../wip/softhsm
.include "../../wip/softhsm/buildlink3.mk"
.endif
