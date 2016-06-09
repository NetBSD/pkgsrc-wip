# $NetBSD: Makefile,v 1.1 2015/08/10 22:03:55 yhardy Exp $

GITHUB_PROJECT=	speedtest-cli
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-0.3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sivel/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sivel/speedtest-cli/
COMMENT=	Command line interface for testing internet bandwidth
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/speedtest-cli-0.3.2
USE_LANGUAGES=	# none

REPLACE_PYTHON+=	speedtest_cli.py

PYDISTUTILSPKG=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
