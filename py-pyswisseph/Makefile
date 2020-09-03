# $NetBSD: Makefile,v 1.4 2014/04/07 04:36:02 othyro Exp $
#

DISTNAME=	pyswisseph-2.00.00-2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-2$/.2/1}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyswisseph/}
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
