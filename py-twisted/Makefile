# $NetBSD: Makefile,v 1.2 2003/05/17 13:53:09 marc Exp $
#

DISTNAME=		Twisted-1.0.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://twisted.sourceforge.net/ \
			http://twistedmatrix.com/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://twisted.sourceforge.net/
COMMENT=		Framework for writing networked applications

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSION_REQD=	22pth

post-install:
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py \
		${PREFIX}/${PYSITELIB}/twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
