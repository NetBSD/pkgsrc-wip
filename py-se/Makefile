# $NetBSD: Makefile,v 1.6 2012/10/16 12:35:14 jihbed Exp $
#

DISTNAME=	pyse-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pyfdm/pyfdm/0.3.1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyfdm.sourceforge.net/
COMMENT=	Framework for solving PDEs with FDM using Python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Pmw>=1.3.2:../../x11/py-Pmw

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
