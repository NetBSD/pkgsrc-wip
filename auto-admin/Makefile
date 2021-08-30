# $NetBSD$

DISTNAME=	auto-admin-0.7.5.15
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	7bfcd294db1e36a3332de68ce752a04c0e426f5d

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
