# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:30 asau Exp $
#

DISTNAME=	SetupDocs-1.0.4.tar
EGG_NAME=	SetupDocs-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/S/s/:S/D/d/:S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SetupDocs/}
EXTRACT_SUFX=	.gz#md5=824bcf896b7e4e7c610d65544e28bdd1

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/setupdocs
COMMENT=	Setuptools plugin that automates building of docs from reST source

DEPENDS+=	${PYPKGPREFIX}-sphinx>=0.6.6:../../textproc/py-sphinx

WRKSRC=		${WRKDIR}/SetupDocs-1.0.4
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
