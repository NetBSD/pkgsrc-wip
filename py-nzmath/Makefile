# $NetBSD: Makefile,v 1.3 2012/04/08 19:09:48 thomasklausner Exp $
#

DISTNAME=	NZMATH-0.90.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/NZMATH/nzmath/}
CATEGORIES=	math python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/nzmath/nzmath/NZMATH-0.90.0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://tnt.math.metro-u.ac.jp/nzmath/
COMMENT=	Number theory oriented calculation system
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
