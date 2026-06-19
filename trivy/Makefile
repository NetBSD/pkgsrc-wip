# $NetBSD$

DISTNAME=	trivy-0.71.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=aquasecurity/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://trivy.dev/
COMMENT=	Comprehensive and versatile security scanner
LICENSE=	apache-2.0

MAKE_ENV+=	GOEXPERIMENT=jsonv2

GOFLAGS+=	-ldflags '-s -w \
		-X github.com/aquasecurity/trivy/pkg/version.ver=${PKGVERSION_NOREV}'

GO_BUILD_PATTERN=	./cmd/trivy

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
