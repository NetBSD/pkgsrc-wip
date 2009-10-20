# $NetBSD: Makefile,v 1.1.1.1 2009/10/20 08:53:32 jihbed Exp $
#

DISTNAME=	greenlet-0.2.tar
PKGNAME=	${PYPKGPREFIX}-greenlet-0.2
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/g/greenlet/
EXTRACT_SUFX=	.gz#md5=cfcac72683fbf52d6c9f4f82a319dcb9

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://undefined.org/python/#greenlet
COMMENT=	Lightweight in-process concurrent programming
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/greenlet-0.2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
