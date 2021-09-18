# $NetBSD$

DISTNAME=	auto-admin-0.7.6.12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	303c686f0add5e43ec4d18d4f131fd531eb8f291

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/auto-admin
COMMENT=	Portable tools for automating systems management
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
