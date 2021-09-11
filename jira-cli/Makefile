# $NetBSD$

DISTNAME=	jira-cli-0.0.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=ankitpokhrel/}
CATEGORIES=	net
GITHUB_TAG=	e89852c1ff914dac3f630aa676d0dd2748867a7b

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/ankitpokhrel/jira-cli
COMMENT=	Feature-rich Interactive Jira Command Line
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/jira
CHECK_RELRO_SKIP+=	bin/jira

INSTALLATION_DIRS+=	bin share/doc/jira-cli

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/jira ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/jira-cli

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
