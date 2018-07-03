# $NetBSD$

DISTNAME=	afl-cov-0.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mrash/afl-cov/
COMMENT=	Produce code coverage results with gcov from afl-fuzz test cases
LICENSE=	gnu-gpl-v2

DEPENDS+=	lcov-[0-9]*:../../devel/lcov
DEPENDS+=	afl-[0-9]*:../../devel/afl

USE_LANGUAGES=	# none

REPLACE_PYTHON+=		afl-cov
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.6

INSTALLATION_DIRS+=	bin share/doc/afl-cov

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/afl-cov ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/afl-cov

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
