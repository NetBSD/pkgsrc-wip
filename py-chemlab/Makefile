# $NetBSD: Makefile,v 1.1 2015/06/10 23:14:45 jihbed Exp $

DISTNAME=	chemlab-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=c/chemlab/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/c/chemlab/
COMMENT=	The python chemistry library you were waiting for
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.4:../../devel/py-nose

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools:build

pre-configure:
	# Verify that no fetching is done during build
	${RM} ${WRKSRC}/distribute_setup.py

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
