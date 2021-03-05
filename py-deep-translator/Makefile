# $NetBSD$

DISTNAME=	deep_translator-1.3.5
PKGNAME=	${PYPKGPREFIX}-deep-translator-1.3.5
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deep_translator/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/nidhaloff/deep_translator
COMMENT=	Tool to translate between different languages
LICENSE=	mit

BUILD_DEPENDS+=	
${PYPKGPREFIX}-test-runner>=5.2:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.9.3:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.2:../../devel/py-test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
