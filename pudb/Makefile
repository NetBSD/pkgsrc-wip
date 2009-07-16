# $NetBSD: Makefile,v 1.1.1.1 2009/07/16 18:02:57 jihbed Exp $
#

DISTNAME=	pudb-0.92.7.tar
PKGNAME=	${DISTNAME:S/.tar//}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pudb/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pudb/
COMMENT=	Curses-based interface to Python debugger
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.1.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.0:../../textproc/py-pygments
#DEPENDS+=	${PYPKGPREFIX}-ipython>=0.9.1:../../wip/py-ipython

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pudb-0.92.7
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
