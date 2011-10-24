# $NetBSD: Makefile,v 1.7 2011/10/24 14:43:16 noud4 Exp $
#

DISTNAME=	papyon-0.4.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://www.freedesktop.org/software/papyon/releases/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Papyon
COMMENT=	MSN client library written in Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.7:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.0:../../security/py-crypto

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26 25
PYDISTUTILSPKG= yes

do-test:
	( cd ${WRKSRC} &&  ${PYTHONBIN} test.py }


.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/farsight2/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
