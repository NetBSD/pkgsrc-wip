# $NetBSD: Makefile,v 1.1.1.1 2011/01/19 14:36:48 jihbed Exp $
#

DISTNAME=	scikits.talkbox-0.2.5
PKGNAME=	${PYPKGPREFIX}-scikits_talkbox-0.2.5
CATEGORIES=	math  python
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.talkbox/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.scipy.org/scipy/scikits
COMMENT=	Talkbox, a set of python modules for speech/signal processing
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/scikits.talkbox-0.2.5

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
