# $NetBSD: Makefile,v 1.6 2013/12/08 22:59:03 noud4 Exp $
#

DISTNAME=	CouchDB-0.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/CouchDB/couchdb/}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/C/CouchDB/
FETCH_USING=	curl
EXTRACT_SUFX=	.tar.gz#md5=446b8377cf2ddda94d5f2df29c4f705f

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/couchdb-python/
COMMENT=	Couchdb python library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.5.0:../../www/py-httplib2

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

REPLACE_PYTHON+=	couchdb/json.py
REPLACE_PYTHON+=	couchdb/tools/dump.py
REPLACE_PYTHON+=	couchdb/tools/load.py
REPLACE_PYTHON+=	couchdb/tools/replication_helper.py
REPLACE_PYTHON+=	couchdb/tools/replication_helper_test.py
REPLACE_PYTHON+=	couchdb/view.py

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/py-couchdb
	cd ${WRKSRC}/doc && pax -rwpe . ${DESTDIR}${PREFIX}/share/doc/py-couchdb

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
