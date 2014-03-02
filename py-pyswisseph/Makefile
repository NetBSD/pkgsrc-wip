# $NetBSD: Makefile,v 1.3 2014/03/02 19:40:43 othyro Exp $
#

DISTNAME=	pyswisseph-2.00.00-1
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
