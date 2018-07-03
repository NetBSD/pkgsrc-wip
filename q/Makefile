# $NetBSD$

DISTNAME=	q-1.5.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=harelba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/harelba/q/
COMMENT=	Command line tool for direct SQL-like queries on CSVs/TSVs
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of q-1.5.0

REPLACE_PYTHON+=	bin/q
INSTALLATION_DIRS+=	bin share/doc/q

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/q ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/USAGE.markdown ${DESTDIR}${PREFIX}/share/doc/q

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
