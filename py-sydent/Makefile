# $NetBSD$

DISTNAME=	${PYPKGPREFIX}-sydent-0.1
CATEGORIES=    	www
GITHUB_PROJECT=	sydent
MASTER_SITES=   ${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_TAG=     v${PKGVERSION_NOREV}
GITHUB_TAG=    	3d3ac5ab802ad91bbecfc0cd6a50bdd31875c1fe
#EXTRACT_SUFX=   .zip

MAINTAINER=     kethzer.dr@gmail.com
HOMEPAGE=       https://github.com/matrix-org/
COMMENT=        Matrix Identity Servers
LICENSE=        apache-2.0

DEPENDS+= ${PYPKGPREFIX}-daemonize>=2.4.7:../../devel/py-daemonize
DEPENDS+= ${PYPKGPREFIX}-phonenumbers-[0-9]*:../../textproc/py-phonenumbers
DEPENDS+= ${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+= ${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial
DEPENDS+= ${PYPKGPREFIX}-signedjson-[0-9]*:../../wip/py-signedjson
DEPENDS+= ${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+= ${PYPKGPREFIX}-unpaddedbase64-[0-9]*:../../wip/py-unpaddedbase64
DEPENDS+= ${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+= ${PYPKGPREFIX}-libnacl-[0-9]*:../../wip/py-libnacl
DEPENDS+= ${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl
DEPENDS+= ${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity


WRKSRC=		${WRKDIR}/sydent-3d3ac5ab802ad91bbecfc0cd6a50bdd31875c1fe
#USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
