# $NetBSD: Makefile,v 1.4 2012/02/01 00:04:53 noud4 Exp $
#

DISTNAME=	mpi4py-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
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

.include "../../lang/python/extension.mk"
.if ${PYVERSSUFFIX} == "2.4"
DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes
.endif
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
