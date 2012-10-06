# $NetBSD: Makefile,v 1.2 2012/10/06 17:13:24 asau Exp $

DISTNAME=	PyClimate-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	geography python
MASTER_SITES=	http://fisica.ehu.es/jsaenz/pyclimate_files/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://www.pyclimate.org/
COMMENT=	Python modules for Analysis of Climate Variability
LICENSE=	gnu-gpl-v2

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	bin

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
