# $NetBSD$

DISTNAME=	spyder-terminal-1.2.2
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spyder-terminal/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/spyder-terminal
COMMENT=	Run system terminals inside Spyder
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	spyder>=5.2.0:../../wip/spyder
DEPENDS+=	${PYPKGPREFIX}-coloredlogs>=14.0:../../devel/py-coloredlogs
DEPENDS+=	${PYPKGPREFIX}-terminado>=0.10.1:../../www/py-terminado
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2:../../www/py-tornado

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
