# $NetBSD$

DISTNAME=	gcalcli-4.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gcalcli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/insanum/gcalcli
COMMENT=	Google Calendar Command Line Interface
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=0:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-babel>=0:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=1.4:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-google-auth-oauthlib>=0:../../security/py-google-auth-oauthlib
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=0:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pydantic>=0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-truststore>=0:../../security/py-truststore

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	pyproject.toml
SUBST_SED.paths=	-e "s,share/man/man1,${PKGMANDIR}/man1,"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/gcalcli ${DESTDIR}${PREFIX}/bin/gcalcli${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gcalcli.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gcalcli${PYVERSSUFFIX}.1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
