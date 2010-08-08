# $NetBSD: Makefile,v 1.1.1.1 2010/08/08 21:03:13 jihbed Exp $
#

DISTNAME=	pycaptcha-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www
MASTER_SITES=	http://releases.navi.cx/pycaptcha/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://svn.navi.cx/misc/trunk/pycaptcha/
COMMENT=	Python framework for CAPTCHA tests
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
