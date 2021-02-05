# $NetBSD$

DISTNAME=	kaf-0.1.39
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=birdayz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/birdayz/kaf
COMMENT=	Apache Kafka Client and CLI written in Go
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./cmd/kaf

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/kaf ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
