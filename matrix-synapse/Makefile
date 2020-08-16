# $NetBSD$

GITHUB_PROJECT=	synapse
GITHUB_TAG=	${DISTNAME}
DISTNAME=	v1.18.0
PKGNAME=	matrix-synapse-${DISTNAME:S,^v,,}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/synapse/
COMMENT=	Reference homeserver for the Matrix decentralised comms protocol
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.5.1:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-frozendict>=1:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64>=1.1.0:../../devel/py-unpaddedbase64
DEPENDS+=	${PYPKGPREFIX}-canonicaljson>=1.1.3:../../devel/py-canonicaljson
DEPENDS+=	${PYPKGPREFIX}-signedjson>=1.1.0:../../security/py-signedjson
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.2.1:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-idna>=2.5:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-service_identity>=18.1.0:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-twisted>=18.9.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-treq>=15.1:../../devel/py-treq
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=16.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.9:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.0.7:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-daemonize>=2.3.1:../../devel/py-daemonize
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.0:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4.3.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=1.4.4:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-macaroons>=0.13.0:../../devel/py-macaroons
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=8.2.0:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>=0.8.0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.4.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.7.18:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.9:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-bleach>=1.4.3:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions

WRKSRC=		${WRKDIR}/synapse-${DISTNAME:S,^v,,}
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
