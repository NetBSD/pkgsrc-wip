# $NetBSD$

DISTNAME=	vorta-0.8.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=borgbase/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://vorta.borgbase.com/
COMMENT=	Graphical interface for borgbackup
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-peewee-[0-9]*:../../databases/py-peewee
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-apscheduler-[0-9]*:../../wip/py-apscheduler

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-pyobjc-core-[0-9]*:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa-[0-9]*:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-LaunchServices-[0-9]*:../../devel/py-pyobjc-framework-LaunchServices
.else
DEPENDS+=	${PYPKGPREFIX}-secretstorage-[0-9]*:../../wip/py-secretstorage
.endif
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
# not packaged yet
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-qt-[0-9]*:../../devel/py-test-qt

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} vorta vorta-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
