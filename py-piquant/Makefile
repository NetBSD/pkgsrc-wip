# $NetBSD: Makefile,v 1.1.1.1 2011/03/07 11:07:27 jihbed Exp $
#

DISTNAME=	piquant-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/p/piquant/
EXTRACT_SUFX=	.zip
# XXX: all text file are DOS style.
# XXX: if future version install binary file,
# XXX: please consider to use another method.
EXTRACT_OPTS_ZIP=	-aaqo


MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://piquant.sourceforge.net/
COMMENT=	TODO: Short description of the package
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
