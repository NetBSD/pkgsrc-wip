# $NetBSD: Makefile,v 1.3 2012/10/14 22:09:25 thomasklausner Exp $
#

DISTNAME=	jsonrequester-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonrequester/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/jsonrequester
COMMENT=	Library for client JSON REST requests
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.6.0:../../www/py-httplib2

WRKSRC=		${WRKDIR}/jsonrequester-0.1.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
