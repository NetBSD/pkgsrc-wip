# $NetBSD: Makefile,v 1.4 2014/12/31 13:58:23 thomasklausner Exp $

DISTNAME=	Pyccuracy-1.2.23
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pyccuracy/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.pyccuracy.org/
COMMENT=	Pyccuracy is a BDD style Acceptance Testing framework
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-selenium>=1.0.1:../../wip/py-selenium

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
