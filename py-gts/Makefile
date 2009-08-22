# $NetBSD: Makefile,v 1.1.1.1 2009/08/22 16:58:41 jihbed Exp $
#

DISTNAME=	pygts-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pygts/pygts/0.3.1/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pygts.sourceforge.net/
COMMENT=	Python bindings for GNU Triangulated Surface Library
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
PY_PATCHPLIST=	yes


.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../wip/gts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
