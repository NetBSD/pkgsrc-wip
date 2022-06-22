# $NetBSD$

DISTNAME=	docker-compose-2.6.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=docker/}
GITHUB_PROJECT=	compose
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/docker/compose
COMMENT=	Define and run multi-container applications with Docker
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	./cmd

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cmd ${DESTDIR}${PREFIX}/bin/docker-compose

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
