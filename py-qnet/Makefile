# $NetBSD: Makefile,v 1.1 2014/10/04 08:30:47 jihbed Exp $

DISTNAME=	QNET-1.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=Q/QNET/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mabuchilab/QNET
COMMENT=	Tools for symbolically analyzing quantum feedback networks
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
#DEPENDS+=	${PYPKGPREFIX}-qutip>=3.0.1:../../wip/py-qutip

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
