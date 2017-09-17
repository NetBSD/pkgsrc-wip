# $NetBSD$

DISTNAME=	mailman-3.1.0b5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailman/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.list.org/
COMMENT=	GNU mailing list manager
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_ACCEPTED=	36 35 34

DEPENDS+=	${PYPKGPREFIX}-aiosmtpd>=1.0a5:../../mail/py-aiosmtpd
DEPENDS+=	${PYPKGPREFIX}-alembic-[0-9]*:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
DEPENDS+=	${PYPKGPREFIX}-dns>=1.14.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-falcon>=1.0.0rc1:../../devel/py-falcon
DEPENDS+=	${PYPKGPREFIX}-flufl.bounce-[0-9]*:../../mail/py-flufl.bounce
DEPENDS+=	${PYPKGPREFIX}-flufl.i18n-[0-9]*:../../devel/py-flufl.i18n
DEPENDS+=	${PYPKGPREFIX}-flufl.lock-[0-9]*:../../devel/py-flufl.lock
DEPENDS+=	${PYPKGPREFIX}-lazr.config-[0-9]*:../../devel/py-lazr.config
DEPENDS+=	${PYPKGPREFIX}-passlib-[0-9]*:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-ZopeComponent-[0-9]*:../../devel/py-ZopeComponent
DEPENDS+=	${PYPKGPREFIX}-ZopeConfiguration-[0-9]*:../../devel/py-ZopeConfiguration
DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

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
