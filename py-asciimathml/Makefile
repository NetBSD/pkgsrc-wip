# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:45 thomasklausner Exp $

DISTNAME=	asciimathml-0.9.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asciimathml/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/favalex/python-asciimathml
COMMENT=	ASCIIMathML to MathML translator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-elementtree

.include "../../lang/python/extension.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
