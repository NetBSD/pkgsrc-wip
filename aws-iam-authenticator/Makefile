# $NetBSD$

DISTNAME=	aws-iam-authenticator-0.5.7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=kubernetes-sigs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kubernetes-sigs/aws-iam-authenticator
COMMENT=	AWS IAM Authenticator for Kubernetes
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X sigs.k8s.io/aws-iam-authenticator/pkg.Version=${GITHUB_TAG} \
			-X sigs.k8s.io/aws-iam-authenticator/pkg.BuildDate="" \
			-X sigs.k8s.io/aws-iam-authenticator/pkg.CommitID=""'
GO_BUILD_PATTERN+=	./cmd/aws-iam-authenticator

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
