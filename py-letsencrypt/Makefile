# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dev//}
CATEGORIES=	security

COMMENT=	Automatically receive and install X.509 certificates on servers
LICENSE=	apache-2.0

EGG_NAME=	${DISTNAME}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # as of 0.1.0

.include "Makefile.common"
.include "../../lang/python/egg.mk"

DEPENDS+=	${PYPKGPREFIX}-acme-${PKGVERSION_NOREV}{nb*,}:../../wip/py-acme
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0.9.3:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.7:../../security/py-cryptography
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-dialog>=3.2.2rc1:../../devel/py-dialog2
.else
DEPENDS+=	${PYPKGPREFIX}-dialog-[0-9]*:../../devel/py-dialog
.endif
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=2.0:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-psutil>=2.1.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-ZopeComponent-[0-9]*:../../devel/py-ZopeComponent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

PKG_SYSCONFSUBDIR=	letsencrypt

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_MESSAGE.path=	Fixing default paths
SUBST_FILES.path+=	letsencrypt/constants.py letsencrypt/display/ops.py
SUBST_FILES.path+=	letsencrypt/renewer.py letsencrypt/tests/*.py
SUBST_SED.path+=	-e 's,/etc/letsencrypt,${PKG_SYSCONFDIR},g'
SUBST_SED.path+=	-e 's,/var/lib/letsencrypt,${VARBASE}/letsencrypt,g'
SUBST_SED.path+=	-e 's,/var/log/letsencrypt,${VARBASE}/letsencrypt/log,g'

MAKE_DIRS+=		${VARBASE}/letsencrypt/log

INSTALLATION_DIRS+=	share/examples/letsencrypt

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/cli.ini \
		${DESTDIR}${PREFIX}/share/examples/letsencrypt

.include "../../mk/bsd.pkg.mk"
