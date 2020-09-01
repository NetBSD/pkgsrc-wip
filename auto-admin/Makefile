# $NetBSD$

DISTNAME=	auto-admin-0.6.7.8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	c3b57eb17f0503c03f43afd085885ef12a731412

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
