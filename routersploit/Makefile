# $NetBSD: Makefile,v 1.4 2017/09/14 12:43:54 leot Exp $

DISTNAME=	routersploit-3.3.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=reverse-shell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/reverse-shell/routersploit
COMMENT=	Exploitation Framework for Embedded Devices
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-snmp-[0-9]*:../../wip/py-snmp

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	rsf.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${RUN} cd ${WRKSRC} && ${TOUCH} routersploit/resources/__init__.py

post-install:
	${INSTALL_DATA_DIR} \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/routersploit/resources/ssh_keys
	${INSTALL_DATA} ${WRKSRC}/routersploit/resources/ssh_keys/* \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/routersploit/resources/ssh_keys
	${INSTALL_DATA_DIR} \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/routersploit/resources/vendors
	${INSTALL_DATA} ${WRKSRC}/routersploit/resources/vendors/* \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/routersploit/resources/vendors
	${INSTALL_DATA_DIR} \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/routersploit/resources/wordlists
	${INSTALL_DATA} ${WRKSRC}/routersploit/resources/wordlists/*.txt \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/routersploit/resources/wordlists

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
