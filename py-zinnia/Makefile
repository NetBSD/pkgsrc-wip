# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 11:14:48 obache Exp $
#

.include "../../wip/zinnia/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

COMMENT=	Zinnia python module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	python

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=${PKGVERSION_NOREV}
.include "../../wip/zinnia/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
