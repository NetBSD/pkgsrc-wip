# $NetBSD$

DISTNAME=	smocker-0.18.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Thiht/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://smocker.dev/
COMMENT=	Simple and efficient HTTP mock server and proxy
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.appName=smocker \
			-X main.buildVersion=${PKGVERSION_NOREV} \
			-X main.buildCommit= \
			-X main.buildDate='

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
