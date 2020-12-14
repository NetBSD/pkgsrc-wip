# $NetBSD$

DISTNAME=	go-jira-1.0.27
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-jira/}
GITHUB_PROJECT=	jira
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/go-jira/jira
COMMENT=	Simple Go command line client for Atlassian's Jira service
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./cmd/jira
CHECK_RELRO_SKIP+=	bin/jira

INSTALLATION_DIRS+=	bin share/doc/go-jira

# XXX: Kludge to disable keyring support: it is supported only on Linux
post-patch:
	${RM} ${WRKSRC}/jiracli/keyring.go

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/jira ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/go-jira

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
