# $NetBSD: Makefile,v 1.2 2011/04/11 23:44:24 jihbed Exp $
#

DISTNAME=	pydelay-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pydelay/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pydelay.sourceforge.net/
COMMENT=	Translates a system of delay differential equations (DDEs)
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
