# $NetBSD$

DISTNAME=	jira-cli-0.0.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=ankitpokhrel/}
CATEGORIES=	net
GITHUB_TAG=	4d08dd5c7a72cf3bbc9b30a4b363b2eaa402cc16

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/ankitpokhrel/jira-cli
COMMENT=	Feature-rich Interactive Jira Command Line
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/jira
CHECK_RELRO_SKIP+=	bin/jira

INSTALLATION_DIRS+=	bin man/man7

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/jira ${DESTDIR}${PREFIX}/bin

post-install:
	${DESTDIR}${PREFIX}/bin/jira man -g -o ${DESTDIR}${PREFIX}/man/man7

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
