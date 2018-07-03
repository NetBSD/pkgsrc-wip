# $NetBSD: Makefile,v 1.4 2012/10/16 07:11:12 thomasklausner Exp $

DISTNAME=	Behaviour-0.1a4
PKGNAME=	${PYPKGPREFIX}-behaviour-0.1
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Behaviour/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/Behaviour/
COMMENT=	Behaviour Driven Development in Python
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.1a4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
