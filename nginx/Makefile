# $NetBSD: Makefile,v 1.12 2007/12/04 17:30:02 ghen Exp $

DISTNAME=		nginx-0.5.33
CATEGORIES=		www
MASTER_SITES=		http://sysoev.ru/nginx/

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://nginx.net/
COMMENT=		Fast lightweight httpd

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ld-opt=-L${PREFIX}/lib\ -Wl,-R${PREFIX}/lib
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sbin-path=${PREFIX}/sbin
CONFIGURE_ARGS+=	--conf-path=${PKG_SYSCONFDIR}/nginx.conf
CONFIGURE_ARGS+=	--pid-path=${VARBASE}/run/nginx.pid
CONFIGURE_ARGS+=	--error-log-path=${NGINX_LOGDIR}/error.log
CONFIGURE_ARGS+=	--http-log-path=${NGINX_LOGDIR}/access.log
CONFIGURE_ARGS+=	--with-mail
CONFIGURE_ARGS+=	--with-mail_ssl_module

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	nginx
NGINX_LOGDIR?=		${VARBASE}/log/nginx
EGDIR=			${PREFIX}/share/examples/nginx

CONF_FILES=		${EGDIR:Q}/conf/fastcgi_params ${PKG_SYSCONFDIR:Q}/fastcgi_params
CONF_FILES+=		${EGDIR:Q}/conf/koi-utf ${PKG_SYSCONFDIR:Q}/koi-utf
CONF_FILES+=		${EGDIR:Q}/conf/koi-win ${PKG_SYSCONFDIR:Q}/koi-win
CONF_FILES+=		${EGDIR:Q}/conf/mime.types ${PKG_SYSCONFDIR:Q}/mime.types
CONF_FILES+=		${EGDIR:Q}/conf/nginx.conf ${PKG_SYSCONFDIR:Q}/nginx.conf
CONF_FILES+=		${EGDIR:Q}/conf/win-utf ${PKG_SYSCONFDIR:Q}/win-utf

INSTALLATION_DIRS=	sbin share/examples/nginx/conf share/examples/nginx/html

OWN_DIRS=		${NGINX_LOGDIR}

BUILD_DEFS+=		PKG_SYSCONFBASE NGINX_LOGDIR VARBASE

BUILD_TARGET=		build

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	conf/nginx.conf
SUBST_SED.paths=	-e 's,%%PKG_SYSCONFDIR%%,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,%%NGINX_LOGDIR%%,${NGINX_LOGDIR},g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/conf/fastcgi_params ${EGDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/conf/koi-utf ${EGDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/conf/koi-win ${EGDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/conf/mime.types ${EGDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/conf/nginx.conf ${EGDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/conf/win-utf ${EGDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/html/50x.html ${EGDIR}/html/
	${INSTALL_DATA} ${WRKSRC}/html/index.html ${EGDIR}/html/

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
