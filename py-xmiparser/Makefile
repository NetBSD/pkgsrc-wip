# $NetBSD: Makefile,v 1.1.1.1 2009/11/25 10:51:45 jihbed Exp $
#

DISTNAME=	xmiparser-1.4.tar
PKGNAME=	${PYPKGPREFIX}-xmiparser-1.4
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/x/xmiparser/
EXTRACT_SUFX=	.gz#md5=b6856526ba82742e3ecab9c62bac7d80

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
