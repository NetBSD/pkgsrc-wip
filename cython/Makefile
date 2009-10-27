# $NetBSD: Makefile,v 1.2 2009/10/27 12:25:51 jihbed Exp $
#

DISTNAME=	Cython-0.11.3
PKGNAME=	cython-0.11.3
CATEGORIES=	lang python
MASTER_SITES=	http://cython.org/release/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://cython.org/
COMMENT=	The Cython compiler for writing C extensions for the Python language
LICENSE=	apache-1.1


PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
