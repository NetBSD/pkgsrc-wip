# $NetBSD: Makefile,v 1.6 2012/09/10 09:17:24 jihbed Exp $
#

DISTNAME=	pudb-0.92.15
PKGNAME=	${EGG_NAME}
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pudb/

MAINTAINER=	pkgsrc-users@NetBSD.org
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

PY_PATCHPLIST=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
