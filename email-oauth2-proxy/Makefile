# $NetBSD$

UPSTR_VERS=	2022-12-14
PVER=		${UPSTR_VERS:S/-/./g}
DISTNAME=	email-oauth2-proxy-${PVER}
#PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_TAG=	${UPSTR_VERS}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=simonrob/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simonrob/email-oauth2-proxy
COMMENT=	IMAP and SMTP proxy supporting Oauth2 authentication
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-timeago-[0-9]*:../../wip/py-timeago
DEPENDS+=	${PYPKGPREFIX}-pystray>=0.19.4:../../wip/py-pystray
DEPENDS+=	${PYPKGPREFIX}-pywebview-[0-9]*:../../wip/py-pywebview

REPLACE_PYTHON+=	emailproxy.py

EGDIR=			${PREFIX}/share/examples/email-oauth2-proxy/
CONF_FILES=		${EGDIR}/emailproxy.config ${PKG_SYSCONFDIR}/emailproxy.config
INSTALLATION_DIRS=	bin ${EGDIR}

do-configure:	# nothing
do-build:	# nothing

do-install:
	${INSTALL} -c -m 644 ${WRKSRC}/emailproxy.config ${DESTDIR}/${EGDIR}/emailproxy.config
	${INSTALL} -c -m 555 ${WRKSRC}/emailproxy.py ${DESTDIR}/${PREFIX}/bin/emailproxy.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
