# $NetBSD: options.mk,v 1.1 2014/01/05 03:42:11 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-uwsgi
PKG_SUPPORTED_OPTIONS=	debug openssl pcre uuid yaml zlib
PKG_SUGGESTED_OPTIONS+=	libxml2 openssl zlib

PKG_OPTIONS_OPTIONAL_GROUPS+=	json xml
PKG_OPTIONS_GROUP.json=		jansson yajl
PKG_OPTIONS_GROUP.xml=		expat libxml2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
# XXX: This doesn't work for some reason.
# XXX: "if self.get('debug')" evaluates to "None". What.
SUBST_SED.options+=		-e 's|debug = false|debug = true|1'
.endif

.if !empty(PKG_OPTIONS:Mexpat)
.include "../../textproc/expat/buildlink3.mk"
SUBST_SED.options+=		-e 's|xml = auto|xml = expat|1'
.elif !empty(PKG_OPTIONS:Mlibxml2)
.include "../../textproc/libxml2/buildlink3.mk"
SUBST_SED.options+=		-e 's|xml = auto|xml = libxml2|1'
.else
SUBST_SED.options+=		-e 's|xml = auto|xml = false|1'
.endif

.if !empty(PKG_OPTIONS:Mjansson)
.include "../../textproc/jansson/buildlink3.mk"
SUBST_SED.options+=		-e 's|json = auto|json = jansson|1'
.elif !empty(PKG_OPTIONS:Myajl)
.include "../../devel/yajl/buildlink3.mk"
SUBST_SED.options+=		-e 's|json = auto|json = yajl|1'
BROKEN=		The yajl option requires a yajl.pc file which that package doesn't have.
.else
SUBST_SED.options+=		-e 's|json = auto|json = false|1'
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
SUBST_SED.options+=		-e 's|ssl = auto|ssl = true|1'
.else
SUBST_SED.options+=		-e 's|ssl = auto|ssl = false|1'
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
SUBST_SED.options+=		-e 's|pcre = auto|pcre = true|1'
.else
SUBST_SED.options+=		-e 's|pcre = auto|pcre = false|1'
.endif

.if !empty(PKG_OPTIONS:Muuid)
.include "../../devel/libuuid/buildlink3.mk"
SUBST_SED.options+=		-e 's|uuid = auto|uuid = true|1'
.else
SUBST_SED.options+=		-e 's|uuid = auto|uuid = false|1'
.endif

.if !empty(PKG_OPTIONS:Myaml)
.include "../../textproc/libyaml/buildlink3.mk"
.else
SUBST_SED.options+=		-e 's|yaml = true|yaml = false|1'
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
.endif
