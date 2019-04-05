# $NetBSD$

DISTNAME=	pypandoc-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	textproc python
MASTER_SITES=	https://files.pythonhosted.org/packages/71/81/00184643e5a10a456b4118fc12c96780823adb8ed974eb2289f29703b29b/

MAINTAINER=	kamekderouiche@yahoo.com
HOMEPAGE=	https://github.com/bebraw/pypandoc
COMMENT=	Thin wrapper for pandoc
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
