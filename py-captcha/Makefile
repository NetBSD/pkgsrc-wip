# $NetBSD: Makefile,v 1.3 2012/10/06 17:55:21 asau Exp $
#

DISTNAME=	pycaptcha-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www
MASTER_SITES=	http://releases.navi.cx/pycaptcha/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://svn.navi.cx/misc/trunk/pycaptcha/
COMMENT=	Python framework for CAPTCHA tests
LICENSE=	mit

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
