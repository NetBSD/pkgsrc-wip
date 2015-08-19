# $NetBSD: Makefile,v 1.1 2015/08/19 14:06:47 triaxx Exp $

DISTNAME=		easy-rsa-${VERSION}
PKGNAME=		easyrsa-${VERSION}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=OpenVPN/easy-rsa/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/OpenVPN/easy-rsa
COMMENT=		Small RSA key management based on openssl command
LICENSE=		gnu-gpl-v2

DEPENDS+=		openssl-[0-9]*:../../security/openssl

VERSION=		3.0.0-rc2
GIT_REPOSITORIES=	easy-rsa
GIT_REPO.easy-rsa=	https://github.com/OpenVPN/easy-rsa.git
GIT_TAG.easy-rsa=	v${VERSION}

WRKSRC=			${WRKDIR}/easy-rsa
INSTALLATION_DIRS+=	${BINDIR} ${EGDIR} ${DOCDIR}
BINDIR=			${PREFIX}/bin
EGDIR=			${PREFIX}/share/examples/easyrsa
DOCDIR=			${PREFIX}/share/doc/easyrsa
DOC_FILES=		COPYING ChangeLog KNOWN_ISSUES README README.quickstart.md

NO_BUILD=		yes

MESSAGE_SUBST+=		EGDIR=${EGDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/easyrsa3/easyrsa ${DESTDIR}${BINDIR}/easyrsa

	${INSTALL_DATA} ${WRKSRC}/easyrsa3/openssl-1.0.cnf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/easyrsa3/vars.example ${DESTDIR}${EGDIR}/vars
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/x509-types
	${INSTALL_DATA} ${WRKSRC}/easyrsa3/x509-types/* ${DESTDIR}${EGDIR}/x509-types

.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
