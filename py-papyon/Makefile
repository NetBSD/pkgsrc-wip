# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:14 thomasklausner Exp $
#

DISTNAME=	papyon-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/papyon/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Papyon
COMMENT=	MSN client library written in Python
LICENSE=	        gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.7:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25
PYDISTUTILSPKG= yes

do-test:
	( cd ${WRKSRC} &&  ${PYTHONBIN} test.py }


.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/farsight2/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
