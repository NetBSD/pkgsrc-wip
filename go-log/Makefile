# $NetBSD$

# XXX 0.0.1 is a made-up release number, ask upstream to make a release.
PKGNAME=	go-log-0.0.1
GITHUB_TAG=	61e686294e58a8698a9e1091268bb4ac1116bd5e
DISTNAME=	log-${GITHUB_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexcesaro/}
GITHUB_PROJECT=	log

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	https://github.com/alexcesaro/log
COMMENT=	Logging packages for Go
LICENSE=	mit

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	log-${GITHUB_TAG}
GO_SRCPATH=	github.com/alexcesaro/log

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
