# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:27 asau Exp $
#

DISTNAME=	Pyevolve-0.6rc1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Pyevolve/pyevolve/}
CATEGORIES=	biology
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pyevolve/Pyevolve/0.6rc1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyevolve.sourceforge.net/
COMMENT=	Complete genetic algorithm framework written in pure python
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-sqlite-[0-9]*:../../databases/py-sqlite3

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
