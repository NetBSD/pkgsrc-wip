# $NetBSD: options.mk,v 1.7 2010/05/09 19:07:53 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		auditor softhsm
PKG_SUGGESTED_OPTIONS=		auditor softhsm

.include "../../mk/bsd.options.mk"

###
### Kasp Auditor
###
.if !empty(PKG_OPTIONS:Mauditor)
.include "../../lang/ruby/buildlink3.mk"
DEPENDS+=	rubygems:../../misc/rubygems
DEPENDS+=	${RUBY_PKGPREFIX}-dnsruby>=1.46:../../net/ruby-dnsruby
.else
CONFIGURE_ARGS+=	--disable-auditor
.endif

###
### SoftHSM
###
.if !empty(PKG_OPTIONS:Msofthsm)
DEPENDS+=	softhsm:../../security/softhsm
.include "../../security/softhsm/buildlink3.mk"
.endif
