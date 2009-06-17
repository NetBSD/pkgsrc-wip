# $NetBSD: Makefile,v 1.1.1.1 2009/06/17 23:30:54 jihbed Exp $
#

DISTNAME=	pylint-0.18.0
PKGNAME=	${PYPKGPREFIX}-logilab-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.logilab.org/pub/pylint/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/857
COMMENT=	Python code static checker and UML diagram generator

DEPENDS+=	${PYPKGPREFIX}-logilab-astng>=0.19.0:../../wip/py-logilab-astng

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
