# $NetBSD$

DISTNAME=		easy-rsa-${VERSION}
PKGNAME=		easyrsa-${VERSION}
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=OpenVPN/easy-rsa/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/OpenVPN/easy-rsa
COMMENT=		Small RSA key management based on openssl command
LICENSE=		gnu-gpl-v2

VERSION=		3.0.1
GIT_REPOSITORIES=	easy-rsa
GIT_REPO.easy-rsa=	https://github.com/OpenVPN/easy-rsa.git
GIT_TAG.easy-rsa=	${VERSION}

EASYRSA_DOC_FILES=	COPYING ChangeLog KNOWN_ISSUES README README.quickstart.md
EASYRSA_CNF_FILES=	openssl-1.0.cnf vars.example x509-types/COMMON x509-types/ca \
			x509-types/client x509-types/server

WRKSRC=			${WRKDIR}/easy-rsa
INSTALLATION_DIRS+=	${BINDIR} ${EGDIR} ${DOCDIR}
BINDIR=			${PREFIX}/bin
EGDIR=			${PREFIX}/share/examples/easyrsa
DOCDIR=			${PREFIX}/share/doc/easyrsa
PKG_SYSCONFSUBDIR=	easyrsa
OWN_DIRS=		${PKG_SYSCONFDIR}/x509-types
.for f in ${EASYRSA_CNF_FILES}
REQD_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/easyrsa3/easyrsa ${DESTDIR}${BINDIR}/easyrsa

	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/x509-types
.for f in ${EASYRSA_CNF_FILES}
	${INSTALL_DATA} ${WRKSRC}/easyrsa3/${f} ${DESTDIR}${EGDIR}/${f}
.endfor

.for f in ${EASYRSA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}

.include "../../wip/mk/git-package.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
