# $NetBSD: Makefile,v 1.1 2010/11/16 15:08:41 haad Exp $
#

DISTNAME=		buildbot-slave-0.8.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=buildbot/}

MAINTAINER=		haad@NetBSD.org
HOMEPAGE=		http://buildbot.sourceforge.net/
COMMENT=		System to automate the compile/test cycle, this is slave part of buildbot.

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

ALL_ENV+=               NO_INSTALL_REQS=1

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=               ${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=               ${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=               ${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=               ${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
