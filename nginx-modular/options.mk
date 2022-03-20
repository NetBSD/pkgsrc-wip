# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.nginx
PKG_SUPPORTED_OPTIONS=	auth-request debug flv geoip gtools gzip http2
PKG_SUPPORTED_OPTIONS+=	image-filter memcache pcre perl realip
PKG_SUPPORTED_OPTIONS+=	secure-link slice ssl status sub uwsgi
PKG_SUGGESTED_OPTIONS=	pcre ssl

PKG_OPTIONS_LEGACY_OPTS+=	v2:http2

PLIST_VARS+=		imagefilter perl uwsgi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--with-debug
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mail_ssl_module
CONFIGURE_ARGS+=	--with-http_ssl_module
SUBST_CLASSES+=		fix-ssl
SUBST_STAGE.fix-ssl=	pre-configure
SUBST_FILES.fix-ssl=	auto/lib/openssl/conf
SUBST_SED.fix-ssl=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.openssl},g'
SUBST_NOOP_OK.fix-ssl=	yes
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
SUBST_CLASSES+=		fix-pcre
SUBST_STAGE.fix-pcre=	pre-configure
SUBST_FILES.fix-pcre=	auto/lib/pcre/conf
SUBST_SED.fix-pcre=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.pcre},g'
SUBST_NOOP_OK.fix-pcre=	yes
.else
CONFIGURE_ARGS+=	--without-pcre
CONFIGURE_ARGS+=	--without-http_rewrite_module
.endif

.if !empty(PKG_OPTIONS:Mflv)
CONFIGURE_ARGS+=	--with-http_flv_module
.endif

.if !empty(PKG_OPTIONS:Mgeoip)
.include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--with-http_geoip_module
SUBST_CLASSES+=		fix-geo
SUBST_STAGE.fix-geo=	pre-configure
SUBST_FILES.fix-geo=	auto/lib/geoip/conf
SUBST_SED.fix-geo=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.GeoIP},g'
SUBST_NOOP_OK.fix-geo=	yes
.endif

.if !empty(PKG_OPTIONS:Mhttp2)
CONFIGURE_ARGS+=	--with-http_v2_module
.endif

.if !empty(PKG_OPTIONS:Msub)
CONFIGURE_ARGS+=	--with-http_sub_module
.endif

.if !empty(PKG_OPTIONS:Mgtools)
CONFIGURE_ARGS+=	--with-google_perftools_module
.include "../../devel/gperftools/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Mmemcache)
CONFIGURE_ARGS+=	--without-http_memcached_module
.endif

.if !empty(PKG_OPTIONS:Mrealip)
CONFIGURE_ARGS+=	--with-http_realip_module
.endif

.if !empty(PKG_OPTIONS:Muwsgi)
EGFILES+=		uwsgi_params
PLIST.uwsgi=		yes
CONFIGURE_ARGS+=	--http-uwsgi-temp-path=${NGINX_DATADIR}/uwsgi_temp
.else
CONFIGURE_ARGS+=	--without-http_uwsgi_module
.endif

.if !empty(PKG_OPTIONS:Mimage-filter)
.include "../../graphics/gd/buildlink3.mk"
SUBST_CLASSES+=		fix-gd
SUBST_STAGE.fix-gd=	pre-configure
SUBST_FILES.fix-gd=	auto/lib/libgd/conf
SUBST_SED.fix-gd=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.gd},g'
SUBST_NOOP_OK.fix-gd=	yes
PLIST.imagefilter=	yes

DSO_BASEMODS+=		http_image_filter_module
.endif

.if !empty(PKG_OPTIONS:Mslice)
CONFIGURE_ARGS+=	--with-http_slice_module
.endif

.if !empty(PKG_OPTIONS:Mstatus)
CONFIGURE_ARGS+=	--with-http_stub_status_module
.endif

.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
INSTALLATION_DIRS+=	${PERL5_INSTALLVENDORARCH}/auto/nginx
PLIST.perl=		yes
.include "../../lang/perl5/dirs.mk"
.include "../../lang/perl5/buildlink3.mk"
DSO_BASEMODS+=		http_perl_module
.endif

.if !empty(PKG_OPTIONS:Mgzip)
CONFIGURE_ARGS+=	--with-http_gzip_static_module
.endif

.if !empty(PKG_OPTIONS:Mauth-request)
CONFIGURE_ARGS+=	--with-http_auth_request_module
.endif

.if !empty(PKG_OPTIONS:Msecure-link)
CONFIGURE_ARGS+=	--with-http_secure_link_module
.endif
