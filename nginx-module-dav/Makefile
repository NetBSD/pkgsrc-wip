# $NetBSD$

DISTNAME=	nginx-dav-ext-module-3.0.0
MASTER_SITE=	${MASTER_SITE_GITHUB:=openresty/array-var-nginx-module}
LICENSE=	2-clause-bsd

NGINX_MODULE=		dav
NGINX_HTTP_MODULES+=	dav_ext

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

SUBST_CLASSES+=		fix-xslt
SUBST_STAGE.fix-xslt=	pre-configure
SUBST_FILES.fix-xslt=	auto/lib/libxslt/conf
SUBST_SED.fix-xslt=	-e 's,/usr/pkg,${BUILDLINK_PREFIX.libxslt},g'
SUBST_NOOP_OK.fix-xslt=	yes

.include "../../wip/nginx-modular/module.mk"
.include "../../mk/bsd.pkg.mk"
