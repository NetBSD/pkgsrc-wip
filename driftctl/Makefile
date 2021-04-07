# $NetBSD$

DISTNAME=	driftctl-0.7.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=cloudskiff/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://driftctl.com/
COMMENT=	Detect, track and alert on infrastructure drift
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/cloudskiff/driftctl/build.env=release \
			-X github.com/cloudskiff/driftctl/pkg/version.version=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
