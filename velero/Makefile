# $NetBSD$

DISTNAME=	velero-1.8.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vmware-tanzu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://velero.io/
COMMENT=	Backup/migrate Kubernetes applications and their persistent volumes
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/vmware-tanzu/velero/pkg/buildinfo.Version=${PKGVERSION_NOREV} \
			-X github.com/vmware-tanzu/velero/pkg/buildinfo.GitSHA= \
			-X github.com/vmware-tanzu/velero/pkg/buildinfo.GitTreeState=clean \
			-X github.com/vmware-tanzu/velero/pkg/buildinfo.ImageRegistry=velero'
GO_BUILD_PATTERN+=	./cmd/velero

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
