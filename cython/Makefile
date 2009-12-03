# $NetBSD: Makefile,v 1.3 2009/12/03 09:09:59 jihbed Exp $
#

DISTNAME=	Cython-0.12
PKGNAME=	cython-0.12
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

DOCDIR=	${PREFIX}/share/doc/cython

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html \
		${DESTDIR}${DOCDIR}
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
