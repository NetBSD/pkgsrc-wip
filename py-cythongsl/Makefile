# $NetBSD: Makefile,v 1.1.1.1 2012/02/01 13:58:39 jihbed Exp $
#

DISTNAME=	CythonGSL-0.1
PKGNAME=	${PYPKGPREFIX}-cythongsl-0.1
CATEGORIES=	devel math python
MASTER_SITES=	http://pypi.python.org/packages/source/C/CythonGSL/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/twiecki/CythonGSL
COMMENT=	Cython declarations for the Gnu Scientific Library
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/CythonGSL-0.1

USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

# work for cython>=1.51.x
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
