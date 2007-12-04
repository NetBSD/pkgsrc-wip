# $NetBSD: Makefile,v 1.10 2007/12/04 16:09:44 ghen Exp $
#

DISTNAME=		nginx-0.5.20
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
CONFIGURE_ARGS+=	--error-log-path=${VARBASE}/log/nginx/error.log
CONFIGURE_ARGS+=	--http-log-path=${VARBASE}/log/nginx/access.log
CONFIGURE_ARGS+=	--with-mail
CONFIGURE_ARGS+=	--with-mail_ssl_module

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	nginx
EGDIR=			${PREFIX}/share/examples/nginx

CONF_FILES=		${EGDIR:Q}/nginx.conf ${PKG_SYSCONFDIR:Q}/nginx.conf
CONF_FILES+=		${EGDIR:Q}/mime.types ${PKG_SYSCONFDIR:Q}/mime.types

BUILD_DEFS+=		PKG_SYSCONFBASE VARBASE

BUILD_TARGET=		build

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
