# $NetBSD$

DISTNAME=	njs-0.7.2
MASTER_SITE=	${MASTER_SITE_GITHUB:=nginx/njs}
LICENSE=	2-clause-bsd

NGINX_MODULE_SUBDIR=	/nginx
NGINX_HTTP_MODULES+=	js
NGINX_STREAM_MODULES+=	js

.include "../../wip/nginx-modular/module.mk"
.include "../../mk/bsd.pkg.mk"
