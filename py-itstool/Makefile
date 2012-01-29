# $NetBSD: Makefile,v 1.1.1.1 2012/01/29 22:27:02 jihbed Exp $
#

DISTNAME=	itstool-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	http://files.itstool.org/itstool/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://itstool.org/
COMMENT=	Tool for translating XML documents with PO files
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

REPLACE_PYTHON+=	itstool.in

.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
