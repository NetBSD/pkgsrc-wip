# $NetBSD$

DISTNAME=	auto-admin-0.6.8.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	7d1f55d4d0344a9aeb5af3bab7905670fa5a3351

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://acadix.biz/auto-admin.php
COMMENT=	Portable tools for automating systems management
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
