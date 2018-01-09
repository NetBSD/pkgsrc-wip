# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.freeswitch
PKG_SUPPORTED_OPTIONS=	zrtp xmlrpc pgsql avmd callcenter cidlookup \
			curl memcache
PKG_SUGGESTED_OPTIONS=	pgsql cidlookup memcache curl

PLIST_VARS+=		callcenter cidlookup avmd curl memcache

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzrtp)
CONFIGURE_ARGS+=	--enable-zrtp
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--enable-core-pgsql-support
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxmlrpc)
CONFIGURE_ARGS+=	--enable-xmlrpc-c
.endif

.if !empty(PKG_OPTIONS:Mcallcenter)
SUBST_CLASSES+=			callcenter
SUBST_STAGE.callcenter=		post-extract
SUBST_MESSAGE.callcenter=	Enabling module Call Center.
SUBST_FILES.callcenter=		modules.conf
SUBST_SED.callcenter=		-e 's:\#applications/mod_callcenter:applications/mod_callcenter:g'

PLIST.callcenter=		yes

#CONF_FILES+=            ${EGDIR}/autoload_configs/callcenter.conf.xml \
#			${PKG_SYSCONFDIR}/autoload_configs/callcenter.conf.xml
.endif

.if !empty(PKG_OPTIONS:Mcidlookup)
SUBST_CLASSES+=			cidlookup
SUBST_STAGE.cidlookup=		post-extract
SUBST_MESSAGE.cidlookup=	Enabling module CID Lookup.
SUBST_FILES.cidlookup=		modules.conf
SUBST_SED.cidlookup=		-e 's:\#applications/mod_cidlookup:applications/mod_cidlookup:g'

PLIST.cidlookup=		yes

#CONF_FILES+=            ${EGDIR}/autoload_configs/cidlookup.conf.xml \
#			${PKG_SYSCONFDIR}/autoload_configs/cidlookup.conf.xml
.endif

.if !empty(PKG_OPTIONS:Mavmd)
SUBST_CLASSES+=		avmd
SUBST_STAGE.avmd=	post-extract
SUBST_MESSAGE.avmd=	Enabling module AVMD (Advanced voicemail beep detection).
SUBST_FILES.avmd=	modules.conf
SUBST_SED.avmd=		-e 's:\#applications/mod_avmd:applications/mod_avmd:g'
PLIST.avmd=		yes
.endif

.if !empty(PKG_OPTIONS:Mcurl)
SUBST_CLASSES+=		curl
SUBST_STAGE.curl=	post-extract
SUBST_MESSAGE.curl=	Enabling module CURL.
SUBST_FILES.curl=	modules.conf
SUBST_SED.curl=		-e 's:\#applications/mod_curl:applications/mod_curl:g'

PLIST.curl=		yes

.include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmemcache)
SUBST_CLASSES+=		memcache
SUBST_STAGE.memcache=	post-extract
SUBST_MESSAGE.memcache=	Enabling module memcached API.
SUBST_FILES.memcache=	modules.conf
SUBST_SED.memcache=	-e 's:\#applications/mod_memcache:applications/mod_memcache:g'

PLIST.memcache=		yes

#CONF_FILES+=            ${EGDIR}/autoload_configs/memcache.conf.xml \
#			${PKG_SYSCONFDIR}/autoload_configs/memcache.conf.xml
.endif

# TODO: Include all remaining modules in options.mk to provide a more customizable package.
