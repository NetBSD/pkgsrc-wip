# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:46 thomasklausner Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	 34 35 36 37 # py-imaging

.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
