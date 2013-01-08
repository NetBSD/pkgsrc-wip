# $NetBSD: Makefile,v 1.2 2013/01/08 03:31:06 othyro Exp $
#

DISTNAME=	pyswisseph-1.77.00-0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-0/.0/1}
CATEGORIES=	time
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyswisseph/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyswisseph.chaosorigin.com/
COMMENT=	Python extension to AstroDienst Swiss Ephemeris
LICENSE=	gnu-gpl-v2

PY_PATCHPLIST=	yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} setup.py install --root=${DESTDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
