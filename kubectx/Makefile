# $NetBSD$

DISTNAME=	kubectx-0.9.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ahmetb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kubectx.dev/
COMMENT=	Faster way to switch between clusters and namespaces in kubectl
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	./cmd/kubectx
GO_BUILD_PATTERN+=	./cmd/kubens

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
