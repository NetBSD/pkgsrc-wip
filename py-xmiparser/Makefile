# $NetBSD: Makefile,v 1.2 2010/08/16 11:17:13 jihbed Exp $
#

DISTNAME=	xmiparser-1.4
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/x/xmiparser/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/xmiparser/
COMMENT=	XMI Parser (API for the UML XML representation specified by OMG)
LICENSE=	gnu-gpl-v2

DEPENDS+=	zope3-[0-9]*:../../www/zope3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xmiparser-1.4
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/doc/py-xmiparser

post-install:
	${INSTALL_DATA} ${WRKSRC}/xmiparser/xmiparser.txt \
		${DESTDIR}${PREFIX}/share/doc/py-xmiparser

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
