# $NetBSD: Makefile,v 1.1.1.1 2011/10/28 18:23:05 jihbed Exp $
#

DISTNAME=	pyreport-0.3.4c
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyreport/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gael-varoquaux.info/computers/pyreport/
COMMENT=	Pyreport makes notes out of a python script
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.8.1:../../textproc/py-docutils

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyreport-0.3.4c

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
