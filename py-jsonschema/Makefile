# $NetBSD: Makefile,v 1.1 2014/02/05 20:38:43 jihbed Exp $

DISTNAME=	jsonschema-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/j/jsonschema/
EXTRACT_SUFX=	.zip#md5=0275f70c5f7c65657555ff478a4fc89c
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/Julian/jsonschema
COMMENT=	Implementation of JSON Schema validation for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
