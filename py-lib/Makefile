# $NetBSD: Makefile,v 1.1.1.1 2009/06/17 23:13:03 jihbed Exp $
#

DISTNAME=	py-1.0.0b1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-1.0.0b1.tar//}lib-1.0.0
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/py/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pylib.org/
COMMENT=	Agile development and test support library
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.5:../../textproc/py-docutils

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/py-1.0.0b1
USE_LANGUAGES=	# none

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
