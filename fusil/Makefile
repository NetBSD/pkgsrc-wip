# $NetBSD: Makefile,v 1.4 2011/08/22 12:42:15 thomasklausner Exp $
#

DISTNAME=	fusil-1.2.1
CATEGORIES=	devel security python
MASTER_SITES=	http://pypi.python.org/packages/source/f/fusil/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://bitbucket.org/haypo/fusil/wiki/Home
COMMENT=	Fuzzing program to test applications
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-ptrace>=0.6:../../wip/py-ptrace
DEPENDS+=	${PYPKGPREFIX}-Xlib-[0-9]*:../../x11/py-Xlib

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=  yes
PYTHON_VERSIONS_INCOMPATIBLE=	24 25

DOCDIR=		${PREFIX}/share/doc/${DISTNAME}
EDGDIR=		${PREFIX}/share/examples/${DISTNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${EDGDIR}


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
