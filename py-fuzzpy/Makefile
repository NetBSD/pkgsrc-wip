# $NetBSD: Makefile,v 1.1.1.1 2010/05/07 10:57:59 jihbed Exp $
#

DISTNAME=	fuzzpy-0.2.1
EGG_NAME=	FuzzPy-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://fuzzpy.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/fuzzpy/
COMMENT=	Fuzzy sets, graphs, and mathematics for Python
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
