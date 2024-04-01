# $NetBSD$

# XXX: Newer versions needs Go 1.22. Wait for pkgsrc Go defaults bump to
# XXX: update it.
DISTNAME=	cilium-cli-0.15.22
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=cilium/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cilium/cilium-cli/
COMMENT=	CLI to manage Kubernetes clusters running Cilium
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/cilium/cilium-cli/defaults.CLIVersion=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/cilium

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
