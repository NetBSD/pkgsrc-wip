# $NetBSD$

DISTNAME=	flux2-0.18.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fluxcd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://toolkit.fluxcd.io/
COMMENT=	Continuous delivery solution for Kubernetes
LICENSE=	apache-2.0

USE_TOOLS+=	bash gmake

TOOL_DEPENDS+=	kustomize-[0-9]*:../../wip/kustomize

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.VERSION=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/flux

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Avoid to use git on non-git repository
SUBST_FILES.path=	manifests/scripts/bundle.sh
SUBST_SED.path+=	-e 's,$$(git rev-parse --show-toplevel),.,g'

REPLACE_BASH+=	manifests/scripts/bundle.sh

# Build the embedded manifests
pre-build:
	${RUN} cd ${WRKSRC} && ${GMAKE} cmd/flux/.manifests.done

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
