# $NetBSD$

DISTNAME=	flux2-2.7.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fluxcd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fluxcd.io/
COMMENT=	Continuous delivery solution for Kubernetes
LICENSE=	apache-2.0

USE_TOOLS+=	bash gmake

TOOL_DEPENDS+=	kustomize-[0-9]*:../../wip/kustomize

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.VERSION=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/flux

REPLACE_BASH+=	manifests/scripts/bundle.sh

# Build the embedded manifests
pre-build:
	${RUN} cd ${WRKSRC} && ${GMAKE} cmd/flux/.manifests.done

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
