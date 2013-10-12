# $NetBSD: Makefile,v 1.1 2013/10/12 13:41:43 thomasklausner Exp $

DISTNAME=	CalendarServer-4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time net
MASTER_SITES=	# manually packaged from release branch in SVN

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.calendarserver.org/
COMMENT=	Standards-compliant server implementing CalDAV and CardDAV protocols
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-CalDAVClientLibrary-[0-9]*:../../wip/py-CalDAVClientLibrary
DEPENDS+=	${PYPKGPREFIX}-Kerberos-[0-9]*:../../security/py-Kerberos
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
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sqlparse-[0-9]*:../../databases/py-sqlparse
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-xattr-[0-9]*:../../sysutils/py-xattr
DEPENDS+=	epydoc-[0-9]*:../../devel/epydoc
DEPENDS+=	memcached-[0-9]*:../../devel/memcached
DEPENDS+=	openldap-client-[0-9]*:../../databases/openldap-client
DEPENDS+=	postgresql91-server-[0-9]*:../../databases/postgresql91-server
DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base

USE_LANGUAGES=	c
USE_TOOLS+=	bash:run

REPLACE_BASH+=	bin/caldavd

REPLACE_PYTHON+=	calendarserver/tools/ampnotifications.py
REPLACE_PYTHON+=	calendarserver/tools/anonymize.py
REPLACE_PYTHON+=	calendarserver/tools/backup.py
REPLACE_PYTHON+=	calendarserver/tools/backup_pg.py
REPLACE_PYTHON+=	calendarserver/tools/calverify.py
REPLACE_PYTHON+=	calendarserver/tools/calverify_diff.py
REPLACE_PYTHON+=	calendarserver/tools/changeip_calendar.py
REPLACE_PYTHON+=	calendarserver/tools/config.py
REPLACE_PYTHON+=	calendarserver/tools/dbinspect.py
REPLACE_PYTHON+=	calendarserver/tools/doublequotefix.py
REPLACE_PYTHON+=	calendarserver/tools/export.py
REPLACE_PYTHON+=	calendarserver/tools/fixcalendardata.py
REPLACE_PYTHON+=	calendarserver/tools/gateway.py
REPLACE_PYTHON+=	calendarserver/tools/loadaugmentdb.py
REPLACE_PYTHON+=	calendarserver/tools/managepostgres.py
REPLACE_PYTHON+=	calendarserver/tools/managetimezones.py
REPLACE_PYTHON+=	calendarserver/tools/migrate.py
REPLACE_PYTHON+=	calendarserver/tools/migrate_verify.py
REPLACE_PYTHON+=	calendarserver/tools/obliterate.py
REPLACE_PYTHON+=	calendarserver/tools/principals.py
REPLACE_PYTHON+=	calendarserver/tools/purge.py
REPLACE_PYTHON+=	calendarserver/tools/push.py
REPLACE_PYTHON+=	calendarserver/tools/resources.py
REPLACE_PYTHON+=	calendarserver/tools/shell/test/test_cmd.py
REPLACE_PYTHON+=	calendarserver/tools/shell/test/test_vfs.py
REPLACE_PYTHON+=	calendarserver/tools/upgrade.py
REPLACE_PYTHON+=	calendarserver/tools/validcalendardata.py
REPLACE_PYTHON+=	calendarserver/tools/warmup.py
REPLACE_PYTHON+=	contrib/certupdate/calendarcertupdate.py
REPLACE_PYTHON+=	contrib/migration/calendarcommonextra.py
REPLACE_PYTHON+=	contrib/migration/calendardemotion.py
REPLACE_PYTHON+=	contrib/migration/calendarmigrator.py
REPLACE_PYTHON+=	contrib/migration/calendarpromotion.py
REPLACE_PYTHON+=	contrib/performance/stackedbar.py
REPLACE_PYTHON+=	twext/python/memcacheclient.py
REPLACE_PYTHON+=	twext/python/test/pullpipe.py
REPLACE_PYTHON+=	twistedcaldav/backup.py
REPLACE_PYTHON+=	twistedcaldav/config.py
REPLACE_PYTHON+=	twistedcaldav/upgrade.py
REPLACE_PYTHON+=	txdav/common/datastore/upgrade/migrate.py
REPLACE_PYTHON+=	txdav/common/datastore/upgrade/sql/upgrade.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
