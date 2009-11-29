# $NetBSD: Makefile,v 1.1.1.1 2009/11/29 21:10:19 jihbed Exp $
#

DISTNAME=	anyjson-0.2.0.tar
PKGNAME=	${PYPKGPREFIX}-anyjson-0.2.0
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/a/anyjson/
EXTRACT_SUFX=	.gz#md5=7890252975a0efa634900e72fcbca875

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/anyjson
COMMENT=	Wraps the JSON implementation available in a common interface
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/anyjson-0.2.0
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
