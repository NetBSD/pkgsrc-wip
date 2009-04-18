# $NetBSD: Makefile,v 1.1.1.1 2009/04/18 23:39:02 jihbed Exp $
#

CHERRYVERS=	3.1.2
DISTNAME=	CherryPy-${CHERRYVERS}
PKGNAME=	${PYPKGPREFIX}-cherry-${CHERRYVERS}
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/cherrypy/${CHERRYVERS}/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.cherrypy.org/
COMMENT=	CherryPy is a pythonic, object-oriented HTTP framework

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.7:../../security/py-OpenSSL

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PYTHON_VERSIONS_ACCEPTED=	25 24 23

.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
