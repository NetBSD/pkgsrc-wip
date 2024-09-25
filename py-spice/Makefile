# $NetBSD$

DISTNAME=	PySpice-1.5
PKGNAME=	${PYPKGPREFIX}-spice
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PySpice/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyspice.fabrice-salvaire.fr/
COMMENT=	Python interface to the Ngspice and Xyce circuit simulators
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/py${PKGVERSION}-post-installation

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
