# $NetBSD: Makefile,v 1.3 2013/07/02 10:26:44 othyro Exp $
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

EGG_NAME=	${DISTNAME:S/-/_/1}

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
