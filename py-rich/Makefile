# $NetBSD$

DISTNAME=	rich-7.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://files.pythonhosted.org/packages/94/66/7455abc9720e282bc073fd907661d095f08d542c24f7beea44d06e447a53/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/willmcgugan/rich
COMMENT=	Render rich text, tables, progress bars, syntax highlighting
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.0:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.9:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
