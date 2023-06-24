# $NetBSD$

DISTNAME=	Mathics_Scanner-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mathics_Scanner/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://mathics.org/
COMMENT=	Character Tables and Tokenizer for Mathics and the Wolfram Language
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-test>=7.2.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-chardet>=5.0.0:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-click>=1.3.8:../../devel/py-click

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
