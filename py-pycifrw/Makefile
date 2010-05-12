# $NetBSD: Makefile,v 1.1.1.1 2010/05/12 16:06:43 jihbed Exp $
#

VERS=	3.1.4
DISTNAME=	PyCifRW-${VERS}
PKGNAME=	${PYPKGPREFIX}-pycifrw-${VERS}
CATEGORIES=	devel
MASTER_SITES=	http://www.diffpy.org/packages/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://anbf2.kek.jp/CIF/index.html
COMMENT=	CIF/STAR file support for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-yapps2>=2.1.1:../../wip/py-yapps2

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
