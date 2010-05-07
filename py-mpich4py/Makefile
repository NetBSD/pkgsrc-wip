# $NetBSD: Makefile,v 1.1.1.1 2010/05/07 22:14:10 jihbed Exp $
#

DISTNAME=	mpi4py-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	http://mpi4py.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/mpi4py/
COMMENT=	MPI for Python - Python bindings for MPI
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
PYDISTUTILSPKG= yes


DOCDIR=	${PREFIX}/share/doc/py-mpi4py

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/mpi4py.pdf ${DESTDIR}${DOCDIR}

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../parallel/mpi-ch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
