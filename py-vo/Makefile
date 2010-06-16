# $NetBSD: Makefile,v 1.1.1.1 2010/06/16 08:51:28 jihbed Exp $
#

DISTNAME=	vo-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math textproc
MASTER_SITES=	http://stsdas.stsci.edu/astrolib/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.stsci.edu/trac/ssb/astrolib
COMMENT=	Python based tools to parse/write VOTABLE file

DEPENDS+=	${PYPKGPREFIX}-pyfits>=2.3.1:../../wip/py-pyfits

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

do-test:
	( cd ${WRKSRC}/test && ${PYTHONBIN} test.py )

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
