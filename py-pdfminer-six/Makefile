# $NetBSD$

DISTNAME=	pdfminer.six-20200726
PKGNAME=	${PYPKGPREFIX}-pdfminer-six-20200726
CATEGORIES=	print python
MASTER_SITES=	https://files.pythonhosted.org/packages/34/4a/bc38040c4a970870ccbef975bae2b6b1bccaa2d308e61111203cccc58e89/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pdfminer/pdfminer.six
COMMENT=	PDF parser and analyzer
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox>=3.12.1:../../devel/py-tox
DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.4:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.9.2:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.2.2:../../devel/py-sortedcontainers

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
