# $NetBSD$

DISTNAME=	kubectl-who-can-0.4.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=aquasecurity/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aquasecurity/kubectl-who-can
COMMENT=	Show RBAC permissions on different resources in Kubernetes
LICENSE=	apache-2.0

.include "go-modules.mk"

#post-install:
#	${MV} ${DESTDIR}${PREFIX}/bin/plugin ${DESTDIR}${PREFIX}/bin/kubectl-ingress-nginx

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
