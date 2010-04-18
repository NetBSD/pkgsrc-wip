# $NetBSD: Makefile,v 1.2 2010/04/18 12:37:40 jihbed Exp $
#

DISTNAME=	dist-python-distutils-extra-2.18
EGG_NAME=	python_distutils_extra-2.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dist-python-//}
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/python-distutils-extra/trunk/2.18/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/python-distutils-extra
COMMENT=	Enhancements to the Python build system
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/python-distutils-extra-2.18
USE_LANGUAGES=	# none

do-test:
	 ( cd ${WRKSRC}/test &&  ${PYTHONBIN} auto.py )

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
