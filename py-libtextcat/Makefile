# $NetBSD: Makefile,v 1.2 2010/08/16 11:00:51 jihbed Exp $
#

DISTNAME=	pylibtextcat-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
EGG_NAME=	${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/p/pylibtextcat/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://proyvind.net/
COMMENT=	Python bindings for libTextCa
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/pylibtextcat-0.1

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test/test_textcat.py

.include "../../lang/python/egg.mk"
.include "../../wip/libtextcat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
