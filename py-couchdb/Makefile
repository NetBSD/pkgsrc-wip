# $NetBSD: Makefile,v 1.3 2012/10/06 17:55:31 asau Exp $
#

DISTNAME=	CouchDB-0.6.tar
PKGNAME=		${PYPKGPREFIX}-couchdb-0.6
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/C/CouchDB/
EXTRACT_SUFX=	.gz#md5=446b8377cf2ddda94d5f2df29c4f705f

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/couchdb-python/
COMMENT=	Couchdb python library
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.5.0:../../wip/py-httplib2

WRKSRC=		${WRKDIR}/CouchDB-0.6
USE_TOOLS+=	pax
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/py-couchdb
	cd ${WRKSRC}/doc && pax -rwpe . ${DESTDIR}${PREFIX}/share/doc/py-couchdb

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
