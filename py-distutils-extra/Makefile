# $NetBSD: Makefile,v 1.7 2014/12/31 13:58:27 thomasklausner Exp $

DISTNAME=	python-distutils-extra-2.38
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/python-distutils-extra/trunk/2.38/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/python-distutils-extra
COMMENT=	Enhancements to the Python build system
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

DOCDIR=		${PREFIX}/share/doc/py-distutils-extra
INSTALLATION_DIRS=	${DOCDIR}

do-test:
	 cd ${WRKSRC}/test &&  ${PYTHONBIN} auto.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
