# $NetBSD$

DISTNAME=	auto-admin-0.6.5.16
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	3b193aade6287e51ff64d69c90ea44d42ceb6fe0

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
