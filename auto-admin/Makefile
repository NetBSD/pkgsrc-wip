# $NetBSD$

DISTNAME=	auto-admin-0.6.7.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	597689496eb1ebae88f50afe388d17057a24824b

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
