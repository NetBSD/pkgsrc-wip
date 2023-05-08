# $NetBSD$

DISTNAME=	mailman-3.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	GNU mailing list manager
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-aiosmtpd>=1.4.3:../../mail/py-aiosmtpd
DEPENDS+=	${PYPKGPREFIX}-alembic>=1.6.2:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
DEPENDS+=	${PYPKGPREFIX}-authheaders>=0.14.0:../../mail/py-authheaders
DEPENDS+=	${PYPKGPREFIX}-authres>=1.0.1:../../mail/py-authres
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dns>=1.14.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-falcon>=3.0.0:../../devel/py-falcon
DEPENDS+=	${PYPKGPREFIX}-flufl.bounce>=4.0:../../mail/py-flufl.bounce
DEPENDS+=	${PYPKGPREFIX}-flufl.i18n>=3.2:../../devel/py-flufl.i18n
DEPENDS+=	${PYPKGPREFIX}-flufl.lock>=5.1:../../devel/py-flufl.lock
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.1.0:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
DEPENDS+=	${PYPKGPREFIX}-lazr.config-[0-9]*:../../devel/py-lazr.config
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-passlib-[0-9]*:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.4.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-ZopeComponent-[0-9]*:../../devel/py-ZopeComponent
DEPENDS+=	${PYPKGPREFIX}-ZopeConfiguration-[0-9]*:../../devel/py-ZopeConfiguration
DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=5.0:../../devel/py-ZopeInterface

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-flufl.testing-[0-9]*:../../devel/py-flufl.testing
BUILD_DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose2-[0-9]*:../../devel/py-nose2

SUBST_CLASSES+=		fhs
SUBST_STAGE.fhs=	pre-configure
SUBST_FILES.fhs=	src/mailman/config/mailman.cfg
SUBST_FILES.fhs+=	src/mailman/core/initialize.py
SUBST_MESSAGE.fhs=	Fixing default paths
SUBST_VARS.fhs=		PKG_SYSCONFDIR PREFIX VARBASE

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
