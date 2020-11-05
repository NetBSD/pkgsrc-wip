# $NetBSD: Makefile,v 1.2 2015/07/16 11:41:46 thomasklausner Exp $

DISTNAME=	Kallithea-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Kallithea/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kallithea-scm.org/
COMMENT=	Fast and powerful management tool for Mercurial and Git
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-PasteScript-[0-9]*:../../www/py-PasteScript
DEPENDS+=	${PYPKGPREFIX}-paste-[0-9]*:../../www/py-paste

DEPENDS+=	${PYPKGPREFIX}-waitress>=0.8.8:../../www/py-waitress
DEPENDS+=	${PYPKGPREFIX}-WebOb>=1.0.8:../../www/py-WebOb
DEPENDS+=	${PYPKGPREFIX}-WebTest>=1.4.:../../www/py-WebTest
DEPENDS+=	${PYPKGPREFIX}-Beaker>=1.6.4:../../wip/py-Beaker
DEPENDS+=	${PYPKGPREFIX}-FormEncode>=1.2.4:../../www/py-FormEncode
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.7.10:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-mako>=0.9.0:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.5:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-Whoosh>=2.4.0:../../textproc/py-Whoosh
DEPENDS+=	${PYPKGPREFIX}-celery>=2.2.5:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-babel>=0.9.6:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.2.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.8.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.5.2:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-crypto>=2.6.0:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-URLObject>=2.3.4:../../www/py-URLObject
DEPENDS+=	${PYPKGPREFIX}-Routes>=1.13:../../www/py-Routes
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.9.9:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-mercurial>=2.9:../../devel/py-mercurial
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=0.3.0:../../security/py-bcrypt

REPLACE_PYTHON+=	kallithea/lib/dbmigrate/migrate/versioning/templates/*.py_tmpl
REPLACE_PYTHON+=	kallithea/tests/scripts/manual_test_crawler.py
REPLACE_PYTHON+=	kallithea/lib/dbmigrate/migrate/versioning/templates/*/*.py_tmpl

USE_LANGUAGES=			# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
