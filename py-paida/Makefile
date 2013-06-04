# $NetBSD: Makefile,v 1.4 2013/06/04 07:45:23 thomasklausner Exp $
#

PKGVERSION=	3.2.1.2.10
DISTNAME=	paida-3.2.1_2.10.1
PKGNAME=	${PYPKGPREFIX}-paida-${PKGVERSION}
CATEGORIES=	math #science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paida/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://paida.sourceforge.net/
COMMENT=	Pure Python scientific analysis package
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	# none
PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
