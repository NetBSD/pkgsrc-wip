# $NetBSD$

DISTNAME=	kustomize-4.1.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kubernetes-sigs/}
GITHUB_TAG=	kustomize/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kubernetes-sigs/kustomize
COMMENT=	Customization of kubernetes YAML configurations
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X sigs.k8s.io/kustomize/api/provenance.version=${PKGVERSION_NOREV} \
			-X sigs.k8s.io/kustomize/api/provenance.gitCommit= \
			-X sigs.k8s.io/kustomize/api/provenance.buildDate='
GO_BUILD_PATTERN+=	.

WRKSRC=		${WRKDIR}/kustomize-kustomize-v${PKGVERSION_NOREV}/kustomize

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
