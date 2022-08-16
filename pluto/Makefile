# $NetBSD$

DISTNAME=	pluto-5.10.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=FairwindsOps/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FairwindsOps/pluto
COMMENT=	Discover deprecated apiVersions in Kubernetes 
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.commit= \
			-X main.version=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/pluto

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
