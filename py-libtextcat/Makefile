# $NetBSD: Makefile,v 1.1.1.1 2010/07/31 12:17:48 jihbed Exp $
#

DISTNAME=	pylibtextcat-0.1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//S/.tar//}
EGG_NAME=	${DISTNAME:S/.tar//}
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/p/pylibtextcat/
EXTRACT_SUFX=	.bz2#md5=531f8fe586a54752d79cf58c9bb82348

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
