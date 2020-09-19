# $NetBSD$

DISTNAME=	backports-datetime-fromisoformat-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/20/15/4bc39da78d00da480ff627398ad25770be1f0c3cf40ea9bc5e9030b441fb/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/movermeyer/backports.datetime_fromisoformat
COMMENT=	Backport of Python 3.7's datetime.fromisoformat
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=0:../../time/py-pytz

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
