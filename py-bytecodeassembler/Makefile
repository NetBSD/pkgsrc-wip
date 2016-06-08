# $NetBSD: Makefile,v 1.2 2012/10/06 17:22:16 asau Exp $
#

DISTNAME=	BytecodeAssembler-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/B/b/S/A/a/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=B/BytecodeAssembler/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/BytecodeAssembler
COMMENT=	Generate Python code objects by assembling bytecode

DEPENDS+=	${PYPKGPREFIX}-decoratortools>=1.8:../../wip/py-decoratortools
DEPENDS+=	${PYPKGPREFIX}-symboltype>=1.0:../../wip/py-symboltype

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
