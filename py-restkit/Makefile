# $NetBSD: Makefile,v 1.1.1.1 2010/04/14 09:31:22 jihbed Exp $
#

DISTNAME=	restkit-1.2.1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/r/restkit/
EXTRACT_SUFX=	.gz#md5=3a4b0fc02e536ee9bacb7d6fe6ccaee8

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/benoitc/restkit/
COMMENT=	Restkit is an HTTP resource kit for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.3.1:../../textproc/py-pygments

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/restkit-1.2.1
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= 24 23 22 21 20

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
