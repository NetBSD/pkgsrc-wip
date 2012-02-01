# $NetBSD: Makefile,v 1.4 2012/02/01 00:04:53 noud4 Exp $
#

DISTNAME=	uuid-1.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/u/uuid/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/uuid/1.30
COMMENT=	UUID object and generation functions
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/uuid-1.30
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.if ${PYVERSSUFFIX} == "2.4"
DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes
.endif
.include "../../mk/bsd.pkg.mk"
