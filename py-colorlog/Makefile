# $NetBSD: Makefile,v 1.1 2015/08/01 22:13:38 jihbed Exp $

DISTNAME=	colorlog-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel sysutils misc
MASTER_SITES=	https://pypi.python.org/packages/source/c/colorlog/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/borntyping/python-colorlog
COMMENT=	Log formatting with colors
LICENSE=	mit

WRKSRC=		${WRKDIR}/colorlog-2.6.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 34 33 27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
