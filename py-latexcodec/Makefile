# $NetBSD: Makefile,v 1.1 2014/02/05 20:49:22 jihbed Exp $

DISTNAME=	latexcodec-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	https://pypi.python.org/packages/source/l/latexcodec/
EXTRACT_SUFX=	.zip
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/mcmtroffaes/latexcodec
COMMENT=	Lexer and codec to work with LaTeX code in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
