# $NetBSD: Makefile,v 1.1 2015/01/20 23:02:46 jihbed Exp $

DISTNAME=	rdoupdate-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rdoupdate/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/yac/rdoupdate
COMMENT=	Managing special packaging/update repository
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	urlgrabber>=3.1.0:../../www/urlgrabber
.include "../../mk/bsd.pkg.mk"
