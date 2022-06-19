# $NetBSD$

DISTNAME=	eksctl-0.102.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=weaveworks/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eksctl.io/
COMMENT=	Official CLI for Amazon EKS
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/weaveworks/eksctl/pkg/version.gitCommit="" \
			-X github.com/weaveworks/eksctl/pkg/version..buildDate=""'
GO_BUILD_PATTERN+=	./cmd/eksctl

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
