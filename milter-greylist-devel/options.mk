# $NetBSD: options.mk,v 1.3 2009/04/13 22:04:53 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.milter-greylist
PKG_SUPPORTED_OPTIONS=		dnsrbl drac spf geoip ldap p0f dkim
PKG_SUGGESTED_OPTIONS=		dnsrbl

.include "../../mk/bsd.options.mk"

###
### DNS Realtime Black List
###
.if !empty(PKG_OPTIONS:Mdnsrbl)
CONFIGURE_ARGS+=	--enable-dnsrbl --with-thread-safe-resolver
.endif

###
### Dynamic Relay Authorization Control
###
.if empty(PKG_OPTIONS:Mdrac)
CONFIGURE_ARGS+=	--disable-drac
.else
DRACD_DB?=		/etc/mail/dracd.db

CONFIGURE_ARGS+=	--enable-drac --with-drac-db=${DRACD_DB}
.endif

###
### Sender Policy Framework
###
.if empty(PKG_OPTIONS:Mspf)
CONFIGURE_ARGS+=	--disable-libspf2
.else
.include "../../mail/libspf2/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libspf2=${PREFIX:Q}
.endif

###
### GeoIP
###
.if empty(PKG_OPTIONS:Mgeoip)
CONFIGURE_ARGS+=	--disable-libGeoIP
.else
.include "../../net/GeoIP/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libGeoIP=${PREFIX:Q}
.endif

###
### OpenLDAP
###
.if empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--disable-openldap
.else
.include "../../www/curl/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openldap=${PREFIX:Q}
.endif

###
### DKIM
###
.if empty(PKG_OPTIONS:Mdkim)
CONFIGURE_ARGS+=	--disable-dkim=${PREFIX:Q}
.else
DEPENDS+=		dkim-milter>=2.6:../../mail/dkim-milter
.include "../../mail/dkim-milter/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libdkim=${PREFIX:Q}
.endif

###
### p0f
###
.if empty(PKG_OPTIONS:Mp0f)
CONFIGURE_ARGS+=	--disable-p0f
.else
DEPENDS+=		../../security/p0f

CONFIGURE_ARGS+=	--with-p0f=${PREFIX:Q}
.endif
