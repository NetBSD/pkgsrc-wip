# $NetBSD: Makefile,v 1.14 2015/04/14 11:56:20 thomasklausner Exp $

DISTNAME=	CalendarServer-6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time net
MASTER_SITES=	# manually packaged from release branch in SVN

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.calendarserver.org/
COMMENT=	Standards-compliant server implementing CalDAV and CardDAV protocols
LICENSE=	apache-2.0

# see
# http://trac.calendarserver.org/browser/CalendarServer/trunk/README.rst
# for instructions for running from SVN; these need to be adapted for
# pkgsrc

DEPENDS+=	${PYPKGPREFIX}-CalDAVClientLibrary-[0-9]*:../../wip/py-CalDAVClientLibrary
DEPENDS+=	${PYPKGPREFIX}-kerberos-[0-9]*:../../security/py-kerberos
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-doctor-[0-9]*:../../devel/py-doctor
DEPENDS+=	${PYPKGPREFIX}-flakes>=0.6:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-ldap-[0-9]*:../../databases/py-ldap
DEPENDS+=	${PYPKGPREFIX}-nevow-[0-9]*:../../www/py-nevow
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-sqlparse-[0-9]*:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-xattr-[0-9]*:../../sysutils/py-xattr
DEPENDS+=	epydoc-[0-9]*:../../devel/epydoc
DEPENDS+=	memcached-[0-9]*:../../devel/memcached
DEPENDS+=	openldap-client-[0-9]*:../../databases/openldap-client
DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-xml via py-nevow, py-psutil, py-Kerberos, py-ldap

USE_TOOLS+=	bash:run

EGG_NAME=	CalendarServer-6.0a.unknown_r14210MS

REPLACE_BASH+=	bin/caldavd

REPLACE_PYTHON+=	calendarserver/tools/*.py
REPLACE_PYTHON+=	calendarserver/tools/shell/test/*.py
REPLACE_PYTHON+=	contrib/performance/*.py
REPLACE_PYTHON+=	contrib/tools/*.py
REPLACE_PYTHON+=	twistedcaldav/*.py
REPLACE_PYTHON+=	txdav/common/datastore/upgrade/migrate.py
REPLACE_PYTHON+=	txdav/common/datastore/upgrade/sql/upgrade.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
