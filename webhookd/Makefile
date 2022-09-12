# $NetBSD$

DISTNAME=	webhookd-1.15.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ncarlier/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ncarlier/webhookd
COMMENT=	Simple webhook server launching shell scripts
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/ncarlier/webhookd/pkg/version.Version=${GITHUB_TAG} \
			-X github.com/ncarlier/webhookd/pkg/version.GitCommit= \
			-X github.com/ncarlier/webhookd/pkg/version.Built='

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
