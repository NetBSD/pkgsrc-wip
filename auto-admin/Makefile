# $NetBSD$

DISTNAME=	auto-admin-0.6.8.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	6cdc4975d1b094bceebd3bcef9b590e348ffa2ac

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
