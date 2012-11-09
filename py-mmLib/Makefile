# $NetBSD: Makefile,v 1.1 2012/11/09 18:30:35 jihbed Exp $
#

DISTNAME=	pymmlib-1.2.0
PKGNAME=	${PYPKGPREFIX}-mmlib-1.2.0
CATEGORIES=	biology python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pymmlib/pymmlib/pymmlib-1.2.0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pymmlib.sourceforge.net/
COMMENT=	Python Macromolecular Library
LICENSE=	artistic

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c fortran
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
