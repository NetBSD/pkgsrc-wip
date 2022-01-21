# $NetBSD$

DISTNAME=	regula-2.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fugue/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://regula.dev/
COMMENT=	Checks infrastructure as code security and compliance
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/fugue/regula/pkg/version.Version=${PKGVERSION_NOREV} \
			-X github.com/fugue/regula/pkg/version.GitCommit='

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
