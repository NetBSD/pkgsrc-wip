# $NetBSD$

DISTNAME=	pyverilog-1.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	category
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyverilog/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/PyHDI/Pyverilog
COMMENT=	Python-based Hardware Design Processing Toolkit for Verilog HDL
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7.1:../../textproc/py-jinja2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
