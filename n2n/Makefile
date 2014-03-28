# $NetBSD: Makefile,v 1.1 2014/03/28 03:48:22 phonohawk Exp $

DISTNAME=	n2n-2.1.0
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.ntop.org/products/n2n/
COMMENT=	Layer Two Peer-to-Peer VPN
LICENSE=	gnu-gpl-v3

# There is no portable way to create TUN/TAP devices, and this is the
# list of platforms on which n2n knows how to do it.
ONLY_FOR_PLATFORM=		Darwin-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*

GIT_REPOSITORIES=		n2n_v2_fork
GIT_REPO.n2n_v2_fork=	git://github.com/lukablurr/n2n_v2_fork.git

RCD_SCRIPTS=			n2n_edge n2n_supernode
DOCDIR=					share/doc/n2n
EGDIR=					share/examples/n2n
PKG_SYSCONFSUBDIR=		n2n
CONF_FILES_PERMS=		${EGDIR}/edge.conf      ${PKG_SYSCONFDIR}/edge.conf      ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
CONF_FILES_PERMS+=		${EGDIR}/supernode.conf ${PKG_SYSCONFDIR}/supernode.conf ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644

N2N_USER?=				n2n
N2N_GROUP?=				n2n
PKG_USERS_VARS+=		N2N_USER
PKG_GROUPS_VARS+=		N2N_GROUP
PKG_USERS=				${N2N_USER}:${N2N_GROUP}
PKG_GROUPS=				${N2N_GROUP}
FILES_SUBST+=			N2N_USER=${N2N_USER}
FILES_SUBST+=			N2N_GROUP=${N2N_GROUP}

USE_TOOLS+=				gmake

WRKSRC=					${WRKDIR}/n2n_v2_fork
NO_CONFIGURE=			yes

INSTALL_MAKE_FLAGS+=	SBINDIR=${DESTDIR}${PREFIX}/sbin
INSTALL_MAKE_FLAGS+=	MAN1DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	MAN7DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
INSTALL_MAKE_FLAGS+=	MAN8DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

INSTALLATION_DIRS+=		${DOCDIR} ${EGDIR}
post-install:
.for f in COPYING HACKING NEW_FEATURES.txt README doc/multiple-supernodes.pdf
	${INSTALL_DATA} ${WRKSRC}/${f}   ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
.for f in edge.conf supernode.conf
	${INSTALL_DATA} ${FILESDIR}/${f} ${DESTDIR}${PREFIX}/${EGDIR}
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
