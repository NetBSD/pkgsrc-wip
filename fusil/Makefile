# $NetBSD: Makefile,v 1.2 2009/08/05 14:10:48 jihbed Exp $
#

DISTNAME=	fusil-1.2.1
CATEGORIES=	devel security python
MASTER_SITES=	http://pypi.python.org/packages/source/f/fusil/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://bitbucket.org/haypo/fusil/wiki/Home
COMMENT=	Fuzzing program to test applications
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-ptrace>=0.6:../../wip/py-ptrace

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=  yes

DOCDIR=		${PREFIX}/share/doc/${DISTNAME}
EDGDIR=		${PREFIX}/share/examples/${DISTNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${DESTDIR}${EDGDIR}


.include "../../lang/python/extension.mk"
.include "../../x11/py-Xlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
