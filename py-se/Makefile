# $NetBSD: Makefile,v 1.1.1.1 2011/03/23 10:21:01 jihbed Exp $
#

DISTNAME=	pyse-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pyfdm/pyfdm/0.3.1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyfdm.sourceforge.net/
COMMENT=	Framework for solving PDEs with FDM using Python
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../x11/py-Pmw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
