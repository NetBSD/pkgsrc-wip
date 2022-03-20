# $NetBSD$
#
# used by wip/nginx-module-cache-purge/Makefile
# used by wip/nginx-module-dav/Makefile
# used by wip/nginx-module-echo/Makefile
# used by wip/nginx-module-encrypted-session/Makefile
# used by wip/nginx-module-form-input/Makefile
# used by wip/nginx-module-geoip2/Makefile
# used by wip/nginx-module-headers-more/Makefile
# used by wip/nginx-module-lua/Makefile
# used by wip/nginx-module-naxsi/Makefile
# used by wip/nginx-module-nchan/Makefile
# used by wip/nginx-module-njs/Makefile
# used by wip/nginx-module-rtmp/Makefile
# used by wip/nginx-module-set-misc/Makefile

PKGNAME?=	nginx-module-${NGINX_MODULE}-${DISTNAME:C/^.*-//}
CATEGORIES?=	www
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER?=	pkgsrc-users@NetBSD.org
COMMENT?=	${NGINX_MODULE} module for the nginx HTTP server

#handle the pcre option
PKG_OPTIONS_VAR=	PKG_OPTIONS.nginx
PKG_SUPPORTED_OPTIONS+=	pcre
PKG_SUGGESTED_OPTIONS=	pcre
.include "../../mk/bsd.options.mk"
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

PATCHDIR=	../../wip/nginx-modular/patches

WRKSRC=		${WRKDIR}/nginx-${NGINX_VERSION}

.include "../../wip/nginx-modular/version.mk"

DEPENDS+=	nginx-modular>=${NGINX_VERSION}:../../wip/nginx-modular

NGINX_DISTFILE=		nginx-${NGINX_VERSION}.tar.gz
DISTFILES+=		${NGINX_DISTFILE}
SITES.${NGINX_DISTFILE}=http://nginx.org/download/

.include "../../wip/nginx-modular/Makefile.common"

BUILD_TARGET=		modules

INSTALLATION_DIRS+=	libexec/nginx

NGINX_MODULE?=		${DISTNAME:C/-[^-]*$//}
NGINX_MODULE_SUBDIR?=	/

CONFIGURE_ARGS+=	--add-dynamic-module=../${DISTNAME}${NGINX_MODULE_SUBDIR}

do-install:
.for mod in ${NGINX_HTTP_MODULES}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/ngx_http_${mod}_module.so ${DESTDIR}${PREFIX}/libexec/nginx
.endfor
.for mod in ${NGINX_STREAM_MODULES}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/ngx_stream_${mod}_module.so ${DESTDIR}${PREFIX}/libexec/nginx
.endfor
.for mod in ${NGINX_OTHER_MODULES}
	${INSTALL_PROGRAM} ${WRKSRC}/objs/ngx_${mod}_module.so ${DESTDIR}${PREFIX}/libexec/nginx
.endfor
