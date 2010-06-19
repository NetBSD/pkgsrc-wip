# $NetBSD: Makefile,v 1.1.1.1 2010/06/19 20:21:01 jihbed Exp $
#

DISTNAME=	SetupDocs-1.0.4.tar
EGG_NAME=	SetupDocs-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/S/s/:S/D/d/:S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/S/SetupDocs/
EXTRACT_SUFX=	.gz#md5=824bcf896b7e4e7c610d65544e28bdd1

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/setupdocs
COMMENT=	Setuptools plugin that automates building of docs from reST source

DEPENDS+=	${PYPKGPREFIX}-sphinx>=0.6.6:../../textproc/py-sphinx

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/SetupDocs-1.0.4
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
