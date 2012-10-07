# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:25 asau Exp $
#

PKGVERSION=	3.2.1.2.10
DISTNAME=	paida-3.2.1_2.10.1
PKGNAME=	${PYPKGPREFIX}-paida-${PKGVERSION}
CATEGORIES=	math #science
MASTER_SITES=	http://garr.dl.sourceforge.net/project/paida/paida/paida-3.2.1_2.10.1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://paida.sourceforge.net/
COMMENT=	Pure Python scientific analysis package
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

USE_LANGUAGES=	# none
PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
