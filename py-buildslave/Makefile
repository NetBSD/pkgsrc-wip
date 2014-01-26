# $NetBSD: Makefile,v 1.8 2014/01/26 15:49:52 thomasklausner Exp $

DISTNAME=		buildbot-slave-0.8.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
EGG_NAME=		${DISTNAME:S|t-|t_|:Q}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=buildbot/}

MAINTAINER=		haad@NetBSD.org
HOMEPAGE=		http://buildbot.sourceforge.net/
COMMENT=		System to automate the compile/test cycle, slave part of buildbot
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=               ${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=               ${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=               ${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=               ${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-twisted

ALL_ENV+=               NO_INSTALL_REQS=1

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
