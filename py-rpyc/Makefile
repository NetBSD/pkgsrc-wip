# $NetBSD: Makefile,v 1.1.1.1 2010/05/16 15:50:56 jihbed Exp $
#

DISTNAME=	rpyc-3.0.7.tar
EGG_NAME=	rpyc-3.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/R/RPyC/
EXTRACT_SUFX=	.gz#md5=49ad8821f990eaf74f483bb0387dd4bf

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://rpyc.wikidot.com/
COMMENT=	Remote Python Call
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/rpyc-3.0.7
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= \
											23 22 21 20 15

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
