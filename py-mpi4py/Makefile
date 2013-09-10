# $NetBSD: Makefile,v 1.1 2013/09/10 21:19:44 jihbed Exp $

DISTNAME=	mpi4py-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	https://bitbucket.org/mpi4py/mpi4py/downloads/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://bitbucket.org/mpi4py/mpi4py/
COMMENT=	MPI for Python - Python bindings for MPI
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

DOCDIR=	${PREFIX}/share/doc/py-mpi4py

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/mpi4py.pdf ${DESTDIR}${DOCDIR}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
