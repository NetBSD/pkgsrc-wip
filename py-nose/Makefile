# $NetBSD: Makefile,v 1.2 2009/08/30 21:20:17 jihbed Exp $
#

DISTNAME=	nose-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://python-nose.googlecode.com/files/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/python-nose/
COMMENT=	Unittest-based testing framework for python
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	pydb>=1.26:../../wip/pydb
DEPENDS+=	${PYPKGPREFIX}-coverage>=3.0:../../wip/py-coverage

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
