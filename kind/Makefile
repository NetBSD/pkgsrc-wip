# $NetBSD$

DISTNAME=	kind-0.30.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kubernetes-sigs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kind.sigs.k8s.io/
COMMENT=	Kubernetes IN Docker, local clusters for testing Kubernetes
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X sigs.k8s.io/kind/pkg/cmd/kind/version.gitCommit= \
			-X sigs.k8s.io/kind/pkg/cmd/kind/version.gitCommitCount='
GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
