# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	pyreport-0.3.4c
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyreport/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gael-varoquaux.info/computers/pyreport/
COMMENT=	Pyreport makes notes out of a python script
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.8.1:../../textproc/py-docutils

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-docutils

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
