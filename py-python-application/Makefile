# $NetBSD: Makefile,v 1.4 2014/08/08 02:07:36 othyro Exp $
#

DISTNAME=	python-application-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-application/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ag-projects.com/
COMMENT=	Basic building blocks for python applications
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/1}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
