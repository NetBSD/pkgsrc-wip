# $NetBSD: Makefile,v 1.9 2011/04/18 00:26:02 silasdb Exp $
#

DISTNAME=		buildbot-0.8.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=buildbot/}

MAINTAINER=		haad@NetBSD.org
HOMEPAGE=		http://buildbot.sourceforge.net/
COMMENT=		System to automate the compile/test cycle

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	27 26 25

ALL_ENV+=               NO_INSTALL_REQS=1

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=               ${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=               ${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=               ${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=               ${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
