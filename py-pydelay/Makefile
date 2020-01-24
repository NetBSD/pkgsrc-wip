# $NetBSD: Makefile,v 1.4 2012/11/12 16:26:49 othyro Exp $
#

DISTNAME=	pydelay-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pydelay/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pydelay.sourceforge.net/
COMMENT=	Translates a system of delay differential equations (DDEs)
LICENSE=	mit

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
