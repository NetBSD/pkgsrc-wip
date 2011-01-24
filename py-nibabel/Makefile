# $NetBSD: Makefile,v 1.1.1.1 2011/01/24 09:29:44 jihbed Exp $
#

DISTNAME=	nibabel-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	science python
MASTER_SITES=	http://pypi.python.org/packages/source/n/nibabel/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://nipy.org/nibabel
COMMENT=	Access a multitude of neuroimaging data formats
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
