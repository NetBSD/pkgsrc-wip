# $NetBSD$

DISTNAME=	ingress-nginx-1.9.1
PKGNAME=	${DISTNAME:S/^/kubectl-/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kubernetes/}
GITHUB_PROJECT=	ingress-nginx
GITHUB_TAG=	controller-v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kubernetes/ingress-nginx
COMMENT=	ingress-nginx kubectl plugin
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X k8s.io/ingress-nginx/version.COMMIT= \
			-X k8s.io/ingress-nginx/version.RELEASE=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/plugin

.include "go-modules.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/plugin ${DESTDIR}${PREFIX}/bin/kubectl-ingress-nginx

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
