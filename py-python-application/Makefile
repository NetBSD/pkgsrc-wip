# $NetBSD: Makefile,v 1.2 2013/06/07 23:13:35 othyro Exp $
#

DISTNAME=	python-application-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-application/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ag-projects.com/
COMMENT=	Basic building blocks for python applications
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
