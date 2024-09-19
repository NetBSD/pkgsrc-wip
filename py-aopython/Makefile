# $NetBSD: Makefile,v 1.2 2012/10/06 17:13:31 asau Exp $
#

DISTNAME=	AOPython-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/AOP/aop/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=A/AOPython/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pieces.openpolitics.com/?s=AOPython
COMMENT=	Aspect Oriented Python
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
