# $NetBSD: Makefile,v 1.2 2003/06/25 15:47:31 xtraeme Exp $
#

DISTNAME=		bitlbee-0.80
CATEGORIES=		chat
MASTER_SITES=		http://www.lintux.cx/downloads/

PATCHFILES=		bitlbee-daemon.patch
PATCH_SITES=		http://xtraeme.unixbsd.org:81/packages/
PATCH_DIST_STRIP=	-p1

MAINTAINER=		jrp@hispabsd.org
HOMEPAGE=		http://www.lintux.cx/downloads/
COMMENT=		IRC to other chat networks gateway

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--bindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--confdir=/var/lib/bitlbee

PKG_SYSCONFSUBDIR=	bitlbee

EGDIR=		${PREFIX}/share/examples/bitlbee
DOCDIR=		${PREFIX}/share/doc/bitlbee

CONF_FILES=	${EGDIR}/motd.txt ${PKG_SYSCONFDIR}/motd.txt

OWN_DIRS=	/var/lib/bitlbee
OWN_DIRS_PERMS=	/var/lib/bitlbee bitlbee bitlbee 750

BITLBEE_USER=	bitlbee
BITLBEE_GROUP=	bitlbee

PKG_GROUPS=     ${BITLBEE_GROUP}
PKG_USERS=	${BITLBEE_USER}:${BITLBEE_GROUP}::Bitlbee\\ user

RCD_SCRIPTS=	bitlbee

do-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bitlbee ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/motd.txt ${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/bitlbee.8 ${PREFIX}/man/man8

.for F in FAQ README TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${F} ${DOCDIR}
.endfor
		
.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
