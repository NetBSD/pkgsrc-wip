# $NetBSD: Makefile,v 1.5 2012/11/12 16:26:49 othyro Exp $
#

DISTNAME=	NZMATH-0.90.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/NZMATH/nzmath/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nzmath/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://tnt.math.metro-u.ac.jp/nzmath/
COMMENT=	Number theory oriented calculation system
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
