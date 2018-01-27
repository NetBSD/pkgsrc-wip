# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:38 thomasklausner Exp $

VERS=		3.1.4
DISTNAME=	PyCifRW-${VERS}
PKGNAME=	${PYPKGPREFIX}-pycifrw-${VERS}
CATEGORIES=	devel
MASTER_SITES=	http://www.diffpy.org/packages/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://anbf2.kek.jp/CIF/index.html
COMMENT=	CIF/STAR file support for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-yapps2>=2.1.1:../../wip/py-yapps2

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-yapps2

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
