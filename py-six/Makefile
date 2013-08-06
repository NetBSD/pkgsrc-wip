# $NetBSD: Makefile,v 1.2 2013/08/06 06:44:01 ahp-nils Exp $
#

DISTNAME=		six-1.3.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=	https://pypi.python.org/packages/source/s/six/
FETCH_USING=	curl

MAINTAINER=		ahp-nils@users.sourceforge.net
HOMEPAGE=		http://pypi.python.org/pypi/six/
COMMENT=		Python 2 and 3 compatibility utilities
LICENSE=		mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
