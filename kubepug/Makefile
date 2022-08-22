# $NetBSD$

DISTNAME=	kubepug-1.4.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rikatz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rikatz/kubepug
COMMENT=	Kubernetes PreUpGrade (Checker)
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X sigs.k8s.io/release-utils/version.gitVersion=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
