# $NetBSD: Makefile,v 1.1.1.1 2011/09/19 23:28:41 jihbed Exp $
#

DISTNAME=	jsonrequester-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www textproc
MASTER_SITES=	http://pypi.python.org/packages/source/j/jsonrequester/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/jsonrequester
COMMENT=	Library for client JSON REST requests
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.6.0:../../wip/py-httplib2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/jsonrequester-0.1.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
