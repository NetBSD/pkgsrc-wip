# $NetBSD$

DISTNAME=	auto-admin-0.6.7.18
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	d2c50572b04ce8c47dac5bf080e4685ff8e76f8a

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/
COMMENT=	Portable tools for automating systems management
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/* ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
