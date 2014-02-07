# $NetBSD: Makefile,v 1.1 2014/02/07 22:35:51 jihbed Exp $

DISTNAME=	watchdog-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	https://pypi.python.org/packages/source/w/watchdog/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/gorakhargosh/watchdog
COMMENT=	Filesystem events monitoring
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-argh>=0.8.1:../../wip/py-argh
DEPENDS+=	${PYPKGPREFIX}-pathtools>=0.1.1:../../wip/py-pathtools

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
