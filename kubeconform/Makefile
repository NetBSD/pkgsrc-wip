# $NetBSD$

DISTNAME=	kubeconform-0.6.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=yannh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/yannh/kubeconform
COMMENT=	Kubernetes manifests validator
LICENSE=	apache-2.0

.include "go-modules.mk"

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/examples

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
