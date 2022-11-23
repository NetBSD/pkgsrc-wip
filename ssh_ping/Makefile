# $NetBSD$

GITHUB_PROJECT=	ssh_ping
GITHUB_TAG=	6c1e3e3090f8340c830195c981892863e395e913
DISTNAME=	ssh_ping-0.20221123
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=jacobsa/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/jacobsa/ssh_ping/
COMMENT=	Utility for measuring SSH session latency
LICENSE=	apache-2.0

USE_LANGUAGES=	# Go

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
