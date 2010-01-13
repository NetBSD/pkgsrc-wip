# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 10:46:57 obache Exp $
#

.include "../../wip/yamcha/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

COMMENT=	YamCha python module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	python

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=${PKGVERSION_NOREV}
.include "../../wip/yamcha/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
