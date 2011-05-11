# $NetBSD: Makefile,v 1.4 2011/05/11 09:26:35 ryo-on Exp $
#

DISTNAME=	python-distutils-extra-2.26
EGG_NAME=	${DISTNAME:S/python-distutils-/python_distutils_/}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/python-distutils-extra/trunk/2.26/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/python-distutils-extra
COMMENT=	Enhancements to the Python build system
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

#WRKSRC=		${WRKDIR}/python-distutils-extra-2.19
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
