# $NetBSD$

DISTNAME=	kubeval-0.16.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=instrumenta/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kubeval.com/
COMMENT=	Validator for Kubernetes configuration files
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	.

#WRKSRC=		${WRKDIR}/kustomize-kustomize-v${PKGVERSION_NOREV}/kustomize

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
