# $NetBSD$

DISTNAME=	readability-lxml-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/readability-lxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/buriy/python-readability
COMMENT=	Fast HTML to text parser (article readability tool)
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=44.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-lxml-html-clean-[0-9]*:../../textproc/py-lxml-html-clean

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
