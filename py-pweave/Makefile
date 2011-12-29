# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:08:13 jihbed Exp $
#

DISTNAME=	Pweave-0.20.1
PKGNAME=	${PYPKGPREFIX}-pweave-0.20.1
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/P/Pweave/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mpastell.com/pweave
COMMENT=	Scientific reports with embedded python computations
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Pweave-0.20.1

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
