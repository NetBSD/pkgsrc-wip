# $NetBSD$

DISTNAME=	cutadapt-4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cutadapt/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://cutadapt.readthedocs.io/en/stable/
COMMENT=	Find and remove adapter sequences, primers, poly-A tails, etc
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
# needed for python 3.11 as of cutadapt 3.5 release
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
# The ALTERNATIVES file has no effect without this, and yet almost
# none of the packages using ALTERNATIVES have this dependency
TOOL_DEPENDS+=	pkg_alternatives-[0-9]*:../../pkgtools/pkg_alternatives
DEPENDS+=	${PYPKGPREFIX}-xopen>=1.6.0:../../devel/py-xopen
DEPENDS+=	${PYPKGPREFIX}-dnaio>=0.10.0:../../wip/py-dnaio

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-xopen

USE_PKG_RESOURCES=	yes

# Trying to use ALTERNATIVES instead
# PYTHON_SELF_CONFLICT=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cutadapt cutadapt-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
