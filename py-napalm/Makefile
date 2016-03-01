# $NetBSD$

DISTNAME=	napalm-0.51.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=napalm-automation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/napalm-automation/napalm/
COMMENT=	Interact with different router vendors using unified API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-netmiko-[0-9]*:../../wip/py-netmiko
DEPENDS+=	${PYPKGPREFIX}-IOSXR-[0-9]*:../../wip/py-IOSXR
DEPENDS+=	${PYPKGPREFIX}-junos-eznc-[0-9]*:../../net/py-junos-eznc
DEPENDS+=	${PYPKGPREFIX}-ncclient-[0-9]*:../../net/py-ncclient
DEPENDS+=	${PYPKGPREFIX}-eapi-[0-9]*:../../wip/py-eapi

# Not yet packaged, this may depend on:
# pyFG		API for FortiOS or how to turn FortiOS into JunOS
# pycsco	Library for working with Cisco NX-OS switches
# bnclient	Blade Network Technologies Netconf Python Client

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	35 34 33 27

# Target dir already exists...
INSTALL_EXTRA_FILES=	napalm/utils/*.yml

post-install:
	cd ${WRKSRC}; \
	for f in ${INSTALL_EXTRA_FILES}; do \
		${INSTALL_DATA} $$f  \
			${DESTDIR}/${PREFIX}/${PYSITELIB}/`dirname $$f`; \
	done

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
