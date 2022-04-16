# $NetBSD$

DISTNAME=	kubeconform-0.4.13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=yannh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yannh/kubeconform
COMMENT=	Kubernetes manifests validator
LICENSE=	apache-2.0

#GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/examples

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
