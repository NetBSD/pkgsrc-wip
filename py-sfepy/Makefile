# $NetBSD: Makefile,v 1.1.1.1 2010/05/10 21:03:59 jihbed Exp $
#

DISTNAME=	sfepy-release-2010.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-release//}
CATEGORIES=	math python
MASTER_SITES=	http://sfepy.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/sfepy/
COMMENT=	Simple finite elements in Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED= 26
PYDISTUTILSPKG= yes

do-test:
	( cd ${WRKSRC} && ${PYTHONBIN} runTests.py )

.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
