# $NetBSD$

DISTNAME=	auto-admin-0.7.5.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	5df64fb706eca5ecb9efbdae2f542d37c642b21a

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
