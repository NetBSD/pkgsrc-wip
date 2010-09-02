# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 12:16:19 jihbed Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
