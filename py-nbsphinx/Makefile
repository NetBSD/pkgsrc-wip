# $NetBSD$

DISTNAME=	nbsphinx-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://files.pythonhosted.org/packages/78/b1/02aeb1c0acfdcd8252afedf74168a3e41d8c6708f9b836cc59552b41d0c3/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://nbsphinx.readthedocs.io/
COMMENT=	Jupyter Notebook Tools for Sphinx
LICENSE=	mit


DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.3.3:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.16:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-nbconvert>=5.6.1:../../www/py-nbconvert
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.0.7:../../www/py-nbformat

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
