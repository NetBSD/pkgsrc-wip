# $NetBSD$

DISTNAME=	k9s-0.32.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=derailed/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://k9scli.io/
COMMENT=	Kubernetes CLI
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/derailed/k9s/cmd.version=${GITHUB_TAG} \
			-X github.com/derailed/k9s/cmd.commit= \
			-X github.com/derailed/k9s/cmd.date='

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
