# $NetBSD: Makefile,v 1.2 2014/03/28 14:10:23 phonohawk Exp $

DISTNAME=	n2n-2.1.0
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://www.ntop.org/products/n2n/
COMMENT=	Layer Two Peer-to-Peer VPN
LICENSE=	gnu-gpl-v3

# There is no portable way to create TUN/TAP devices, and this is the
# list of platforms on which n2n knows how to do it.
ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*

GIT_REPOSITORIES=	n2n
GIT_REPO.n2n=		git://github.com/meyerd/n2n

RCD_SCRIPTS=		n2n_edge n2n_supernode
DOCDIR=			share/doc/n2n
EGDIR=			share/examples/n2n
PKG_SYSCONFSUBDIR=	n2n
CONF_FILES_PERMS=	${EGDIR}/edge.conf      ${PKG_SYSCONFDIR}/edge.conf      ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
CONF_FILES_PERMS+=	${EGDIR}/supernode.conf ${PKG_SYSCONFDIR}/supernode.conf ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644

N2N_USER?=		n2n
N2N_GROUP?=		n2n
PKG_USERS_VARS+=	N2N_USER
PKG_GROUPS_VARS+=	N2N_GROUP
PKG_USERS=		${N2N_USER}:${N2N_GROUP}
PKG_GROUPS=		${N2N_GROUP}
FILES_SUBST+=		N2N_USER=${N2N_USER}
FILES_SUBST+=		N2N_GROUP=${N2N_GROUP}

USE_TOOLS+=		gmake
USE_CMAKE=		YES
USE_LANGUAGES=		c c++

WRKSRC=			${WRKDIR}/n2n/n2n_v2

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}
post-install:
.for f in COPYING HACKING NEW_FEATURES.txt README
	${INSTALL_DATA} ${WRKSRC}/${f}   ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
.for f in edge.conf supernode.conf
	${INSTALL_DATA} ${FILESDIR}/${f} ${DESTDIR}${PREFIX}/${EGDIR}
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
