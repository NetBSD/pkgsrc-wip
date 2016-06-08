# $NetBSD: Makefile,v 1.1 2014/05/04 22:44:15 jihbed Exp $

DISTNAME=	cliff-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cliff/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/python-cliff
COMMENT=	Command Line Interface Formulation Framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.1:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-prettytable>=0.6.1:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-cmd2>=0.6:../../wip/py-cmd2
DEPENDS+=	${PYPKGPREFIX}-stevedore>=0.14.1:../../wip/py-stevedore

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

