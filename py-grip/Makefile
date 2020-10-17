# $NetBSD$

DISTNAME=	grip-4.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/3c/ea/2a475ed37e1b6476182e71223c98667f51704bdbc919608372b203c7ea04/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/joeyespo/grip/
COMMENT=	Render local readme files before sending off to GitHub
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.4.0:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-flask>=1.1.2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.5.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-path-and-address>=2.0.1:../../wip/py-path-and-address
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.6:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.1:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
