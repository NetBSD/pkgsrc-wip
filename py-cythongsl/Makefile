# $NetBSD: Makefile,v 1.2 2012/10/06 17:55:31 asau Exp $
#

DISTNAME=	CythonGSL-0.1
PKGNAME=	${PYPKGPREFIX}-cythongsl-0.1
CATEGORIES=	devel math python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CythonGSL/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/twiecki/CythonGSL
COMMENT=	Cython declarations for the Gnu Scientific Library
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/CythonGSL-0.1

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

# work for cython>=1.51.x
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
