# $NetBSD: Makefile,v 1.1 2015/06/21 18:14:18 jihbed Exp $

DISTNAME=	mistune-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://pypi.python.org/packages/source/m/mistune/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/lepture/mistune
COMMENT=	The fastest markdown parser in pure Python
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/mistune-0.6

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 34 33 27

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
