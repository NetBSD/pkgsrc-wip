# $NetBSD: options.mk,v 1.5 2010/04/12 21:41:21 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.opendnssec
PKG_SUPPORTED_OPTIONS=		auditor softhsm
PKG_SUGGESTED_OPTIONS=		auditor softhsm

.include "../../mk/bsd.options.mk"

###
### Kasp Auditor
###
.if empty(PKG_OPTIONS:Mauditor)
CONFIGURE_ARGS+=	--disable-auditor
.else
.include "../../lang/ruby/buildlink3.mk"

DEPENDS+=	rubygems:../../misc/rubygems
DEPENDS+=	${RUBY_PKGPREFIX}-dnsruby>=1.43:../../net/ruby-dnsruby
.endif

###
### SoftHSM
###
.if empty(PKG_OPTIONS:Msofthsm)

.else

#DEPENDS+=	softhsm:../../security/softhsm
.include "../../security/softhsm/buildlink3.mk"
.endif
