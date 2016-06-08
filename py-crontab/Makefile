# $NetBSD: Makefile,v 1.1 2015/01/05 20:50:50 jihbed Exp $

DISTNAME=	python-crontab-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-crontab/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/python-crontab
COMMENT=	Python Crontab API
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
