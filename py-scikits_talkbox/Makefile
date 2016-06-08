# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scikits.talkbox-0.2.5
PKGNAME=	${PYPKGPREFIX}-scikits_talkbox-0.2.5
CATEGORIES=	math  python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikits.talkbox/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.scipy.org/scipy/scikits
COMMENT=	Talkbox, a set of python modules for speech/signal processing
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/scikits.talkbox-0.2.5

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
