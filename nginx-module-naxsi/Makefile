# $NetBSD$

DISTNAME=	naxsi-1.3
MASTER_SITE=	${MASTER_SITE_GITHUB:=nbs-system/naxsi}
LICENSE=	2-clause-bsd

CONF_FILES+=	${EGDIR}/conf/naxsi_core.rules ${PKG_SYSCONFDIR}/naxsi_core.rules

NGINX_HTTP_MODULES+=	naxsi
NGINX_MODULE_SUBDIR=	/naxsi_src

.include "../../wip/nginx-modular/module.mk"
.include "../../mk/bsd.pkg.mk"
