# $NetBSD: Makefile,v 1.2 2012/10/16 09:30:53 jihbed Exp $
#

DISTNAME=	pkginfo-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pkginfo/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pkginfo/
COMMENT=	Query metadatdata from sdists / bdists / installed packages
LICENSE=	python-software-foundation

WRKSRC=		${WRKDIR}/pkginfo-0.9

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X=yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
