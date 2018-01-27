# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:26 asau Exp $
#

DISTNAME=		piquant-0.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_PYPI:=p/piquant/}
EXTRACT_SUFX=		.zip
# XXX: all text file are DOS style.
# XXX: if future version install binary file,
# XXX: please consider to use another method.
EXTRACT_OPTS_ZIP=	-aaqo


MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sourceforge.net/projects/piquant/
COMMENT=	Extending NumPy and SciPy to specification of numbers and arrays
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
