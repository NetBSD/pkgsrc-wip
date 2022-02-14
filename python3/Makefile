# $NetBSD$
#

PKGNAME=	python3-3
CATEGORIES=	python meta-pkgs
MASTER_SITES=	# empty

MAINTAINER=	bacon@NetBSD.org
COMMENT=	Wrapper linking current python3.x to python3 and python
LICENSE=	python-software-foundation

NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${LN} -s ${PYTHONBIN} ${DESTDIR}${PREFIX}/bin/python3
	${LN} -s ${PYTHONBIN} ${DESTDIR}${PREFIX}/bin/python

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
