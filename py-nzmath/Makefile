# $NetBSD: Makefile,v 1.1.1.1 2010/09/06 13:52:20 jihbed Exp $
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

PYTHON_VERSIONS_ACCEPTED= 26 25
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
