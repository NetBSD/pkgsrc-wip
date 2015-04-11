# $NetBSD: Makefile,v 1.4 2015/04/11 14:42:32 thomasklausner Exp $

DISTNAME=	pycscope-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pycscope/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pycscope/
COMMENT=	Generates a cscope index of Python source trees
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/doc/py-cscope

post-install:
	${INSTALL_DATA} ${WRKSRC}/README  \
		${DESTDIR}${PREFIX}/share/doc/py-cscope

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
