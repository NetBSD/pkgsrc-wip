# $NetBSD: Makefile,v 1.2 2006/09/14 22:06:52 neimal Exp $
#

DISTNAME=		nginx-0.4.2
CATEGORIES=		www
MASTER_SITES=		http://sysoev.ru/nginx/

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://nginx.net/
COMMENT=		Fast lightweight httpd

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

PKG_SYSCONFBASE=	${PREFIX}/etc
PKG_SYSCONFSUBDIR=	nginx
#CDIR=			${PKG_SYSCONFDIR}

#CONF_FILES=		${CDIR}/nginx.conf ${CDIR}/nginx.conf.default
#CONF_FILES+=		${CDIR}/koi-win ${CDIR}/koi-utf ${CDIR}/win-utf
#CONF_FILES+=		${CDIR}/mime.types ${CDIR}/mime.types.default

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sbin-path=${PREFIX}/sbin
CONFIGURE_ARGS+=	--conf-path=${PKG_SYSCONFDIR}/nginx.conf
CONFIGURE_ARGS+=	--pid-path=${VARBASE}/run/nginx.pid
CONFIGURE_ARGS+=	--error-log-path=${VARBASE}/log/nginx/error.log
CONFIGURE_ARGS+=	--http-log-path=${VARBASE}var/log/nginx/access.log

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
