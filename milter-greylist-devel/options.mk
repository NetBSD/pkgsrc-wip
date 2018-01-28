# $NetBSD: options.mk,v 1.5 2009/11/01 23:45:57 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.milter-greylist
PKG_SUPPORTED_OPTIONS=		dnsrbl drac spf geoip ldap dkim p0f spamassassin postfix
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

CONFIGURE_ARGS+=	--with-libspf2=${PREFIX}
.endif

###
### GeoIP
###
.if empty(PKG_OPTIONS:Mgeoip)
CONFIGURE_ARGS+=	--disable-libGeoIP
.else
.include "../../net/GeoIP/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libGeoIP=${PREFIX}
.endif

###
### OpenLDAP
###
.if empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--disable-openldap
.else
.include "../../www/curl/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"

CONFIGURE_ARGS+=	--with-openldap=${PREFIX}
.endif

###
### DKIM
###
.if empty(PKG_OPTIONS:Mdkim)
CONFIGURE_ARGS+=	--disable-dkim
.else
DEPENDS+=		dkim-milter>=2.6:../../mail/dkim-milter
.include "../../mail/dkim-milter/buildlink3.mk"

CONFIGURE_ARGS+=	--with-libdkim=${PREFIX}
.endif

###
### p0f
###
.if empty(PKG_OPTIONS:Mp0f)
CONFIGURE_ARGS+=	--disable-p0f
.else
DEPENDS+=		p0f-[0-9]*:../../security/p0f

CONFIGURE_ARGS+=	--with-p0f=${PREFIX}
.endif

###
### spamassassin
###
.if empty(PKG_OPTIONS:Mspamassassin)
CONFIGURE_ARGS+=	--disable-p0f
.else
DEPENDS+=		spamassassin-[0-9]*:../../mail/spamassassin
CONFIGURE_ARGS+=	--enable-spamassassin
.endif

###
### postfix
###
.if empty(PKG_OPTIONS:Mpostfix)
CONFIGURE_ARGS+=	--disable-postfix
.else
CONFIGURE_ARGS+=	--enable-postfix
.endif
