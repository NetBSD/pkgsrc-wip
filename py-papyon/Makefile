# $NetBSD: Makefile,v 1.12 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	papyon-0.4.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://www.freedesktop.org/software/papyon/releases/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://telepathy.freedesktop.org/wiki/Papyon
COMMENT=	MSN client library written in Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.7:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.0:../../security/py-crypto

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gstreamer0.10, py-gobject

do-test:
	( cd ${WRKSRC} &&  ${PYTHONBIN} test.py }


.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/farsight2/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
