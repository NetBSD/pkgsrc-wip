# $NetBSD: Makefile,v 1.1 2015/08/05 20:34:07 jihbed Exp $

DISTNAME=	PyCBC-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//tl}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyCBC/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/ligo-cbc/pycbc
COMMENT=	Gravitational wave CBC analysis toolkit
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

WRKSRC=		${WRKDIR}/PyCBC-1.1.0

USE_TOOLS+=	bash

REPLACE_BASH+=	bin/pycbc_submit_dax \
						bin/pycbc_submit_dax_stampede

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
