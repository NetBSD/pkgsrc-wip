# $NetBSD: Makefile,v 1.4 2010/02/10 12:22:43 jihbed Exp $
#

DISTNAME=	pudb-0.92.15.tar
PKGNAME=	${DISTNAME:S/.tar//}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pudb/
EXTRACT_SUFX=	.gz#md5=e0b469099b8ab67a4b75e4266b9e659c

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pudb/
COMMENT=	Curses-based interface to Python debugger
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.1.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.0:../../textproc/py-pygments
#DEPENDS+=	${PYPKGPREFIX}-ipython>=0.9.1:../../wip/py-ipython

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pudb-0.92.15
USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
