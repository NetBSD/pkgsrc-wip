# $NetBSD$

DISTNAME=	amply-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/7f/11/33cb09557ac838d9488779b79e05a2a3c1f3ce9747cd242ba68332736778/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/willu47/amply
COMMENT=	Allows you to load and manipulate AMPL/GLPK data as Python
LICENSE=	eclipse-license

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.16:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.4.7:../../devel/py-pyparsing

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
