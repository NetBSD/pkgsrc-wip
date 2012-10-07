# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:27 asau Exp $
#

DISTNAME=	pydelay-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pydelay/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pydelay.sourceforge.net/
COMMENT=	Translates a system of delay differential equations (DDEs)
LICENSE=	mit

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
