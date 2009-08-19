# $NetBSD: Makefile,v 1.2 2009/08/19 23:27:29 jihbed Exp $
#

DISTNAME=	py-1.0.1.tar
PKGNAME=	${PYPKGPREFIX}-lib-1.0.1
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/py/
EXTRACT_SUFX=	.gz#md5=d64444015bac78e0c73ac285f9423750

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pylib.org/
COMMENT=	Agile development and test support library
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.5:../../textproc/py-docutils

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/py-1.0.1
USE_LANGUAGES=	# none

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
