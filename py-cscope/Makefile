# $NetBSD: Makefile,v 1.3 2012/10/06 17:55:31 asau Exp $
#

DISTNAME=	pycscope-0.3.tar
VERSION=	0.3
PKGNAME=	${PYPKGPREFIX}-cscope-${VERSION}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pycscope/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pycscope/
COMMENT=	Generates a cscope index of Python source trees
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/pycscope-0.3
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/doc/py-cscope

post-install:
	${INSTALL_DATA} ${WRKSRC}/README  \
		${DESTDIR}${PREFIX}/share/doc/py-cscope

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
