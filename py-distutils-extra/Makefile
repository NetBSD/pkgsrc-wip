# $NetBSD: Makefile,v 1.3 2010/06/20 12:14:42 jihbed Exp $
#

DISTNAME=	dist-python-distutils-extra-2.19
EGG_NAME=	python_distutils_extra-2.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dist-python-//}
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/python-distutils-extra/trunk/2.19/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/python-distutils-extra
COMMENT=	Enhancements to the Python build system
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/python-distutils-extra-2.19
USE_LANGUAGES=	# none

DOCDIR=	${PREFIX}/share/doc/py-distutils-extra

do-test:
	 ( cd ${WRKSRC}/test &&  ${PYTHONBIN} auto.py )

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
