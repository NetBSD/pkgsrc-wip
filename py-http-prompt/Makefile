# $NetBSD$

DISTNAME=	http-prompt-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/55/aa/5039344dea3f1db6b9ed883378374b867aae605f21734d5de49c206e9f18/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/eliangcs/http-prompt
COMMENT=	Interactive HTTP command-line client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-httpie>=0.9.2:../../www/py-httpie
DEPENDS+=	${PYPKGPREFIX}-parsimonious>=0.6.2:../../wip/py-parsimonious
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.7:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.1.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
