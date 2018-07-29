# $NetBSD$

DISTNAME=	synapse-0.22.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat
GITHUB_PROJECT=	synapse
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Matrix is an open federated Instant Messaging and VoIP
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-daemonize-[0-9]*:../../devel/py-daemonize
DEPENDS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-ujson-[0-9]*:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-phonenumbers-[0-9]*:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-frozendict-[0-9]*:../../wip/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64-[0-9]*:../../wip/py-unpaddedbase64
DEPENDS+=	${PYPKGPREFIX}-canonicaljson-[0-9]*:../../wip/py-canonicaljson
DEPENDS+=	${PYPKGPREFIX}-pymacaroons-[0-9]*:../../wip/py-macaroons
DEPENDS+=	${PYPKGPREFIX}-cryptodomex-[0-9]*:../../wip/py-cryptodomex
DEPENDS+=	${PYPKGPREFIX}-matrix-angular-sdk-[0-9]*:../../wip/py-matrix-angular-sdk
DEPENDS+=	${PYPKGPREFIX}-pydenticon-[0-9]*:../../wip/py-pydenticon
DEPENDS+=	${PYPKGPREFIX}-pysaml2-[0-9]*:../../wip/py-pysaml2
DEPENDS+=	${PYPKGPREFIX}-repoze.who-[0-9]*:../../wip/py-repoze.who
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-signedjson-[0-9]*:../../wip/py-signedjson
DEPENDS+=	${PYPKGPREFIX}-blist-[0-9]*:../../wip/py-blist
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema

DEPENDS+=	zip>=3.0:../../archivers/zip
DEPENDS+=	freetype>=1.5:../../graphics/freetype

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../mk/bsd.prefs.mk"

SYNAPSE_USER?=		synapse
SYNAPSE_GROUP?=		synapse
SYNAPSE_DATADIR?=	${VARBASE}/db/synapse
SYNAPSE_LOGDIR?=	${VARBASE}/log/synapse
SYNAPSE_PIDDIR?=	${VARBASE}/run

BUILD_DEFS+=		SYNAPSE_DATADIR SYNAPSE_LOGDIR SYNAPSE_PIDDIR VARBASE

PKG_USERS_VARS=		SYNAPSE_USER
PKG_GROUPS_VARS+=	SYNAPSE_GROUP
PKG_GROUPS=		${SYNAPSE_GROUP}
PKG_USERS=		${SYNAPSE_USER}:${SYNAPSE_GROUP}

PKG_GECOS.${SYNAPSE_USER}=	SYNAPSE chat server user
PKG_HOME.${SYNAPSE_USER}=	${SYNAPSE_DATADIR}
PKG_SHELL.${SYNAPSE_USER}=	${NOLOGIN}

RCD_SCRIPTS=		synapse
INSTALLATION_DIRS=	bin ${PYSITELIB}

MAKE_DIRS+=		${SYNAPSE_PIDDIR}
OWN_DIRS=		${SYNAPSE_DATADIR}
OWN_DIRS+=		${SYNAPSE_LOGDIR}
OWN_DIRS_PERMS+=	${SYNAPSE_DATADIR} ${SYNAPSE_USER} ${SYNAPSE_GROUP} 0700
OWN_DIRS_PERMS+=	${SYNAPSE_LOGDIR} ${SYNAPSE_USER} ${SYNAPSE_GROUP} 0750

.include "options.mk"

.include "../../x11/tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
