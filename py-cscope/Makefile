# $NetBSD: Makefile,v 1.2 2010/06/04 12:07:05 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pycscope-0.3
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/doc/py-cscope

post-install:
	${INSTALL_DATA} ${WRKSRC}/README  \
		${DESTDIR}${PREFIX}/share/doc/py-cscope

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
