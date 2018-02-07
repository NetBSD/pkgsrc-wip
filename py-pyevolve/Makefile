# $NetBSD: Makefile,v 1.5 2012/11/12 16:26:49 othyro Exp $

DISTNAME=	Pyevolve-0.6rc1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Pyevolve/pyevolve/}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyevolve/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyevolve.sourceforge.net/
COMMENT=	Complete genetic algorithm framework written in pure python
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
