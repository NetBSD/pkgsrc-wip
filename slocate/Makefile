# $NetBSD: Makefile,v 1.10 2007/11/17 14:36:51 hoka_adam Exp $
#

DISTNAME=		slocate-3.1
CATEGORIES=		sysutils
MASTER_SITES=	http://slocate.trakker.ca/files/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://slocate.trakker.ca/
COMMENT=		Secure Locate

NO_CONFIGURE=		YES
USE_TOOLS+=			gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SLOCATE_GROUP?=		slocate
PKG_GROUPS=			${SLOCATE_GROUP}
PKG_GROUPS_VARS+=	SLOCATE_GROUP

EGDIR=				${PREFIX}/share/examples/slocate
MESSAGE_SUBST+=     EGDIR=${EGDIR}

OWN_DIRS=			${PREFIX}/var/slocate
OWN_DIRS_PERMS+=	${PREFIX}/var/slocate ${ROOT_USER} ${SLOCATE_GROUP} 0750

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/slocate ${PREFIX}/bin/
	${CHOWN} ${ROOT_USER}:${SLOCATE_GROUP} ${PREFIX}/bin/slocate
	${CHMOD} 2755 ${PREFIX}/bin/slocate
	${LN} -f -s ${PREFIX}/bin/slocate ${PREFIX}/bin/locate
	${LN} -f -s ${PREFIX}/bin/slocate ${PREFIX}/bin/updatedb
	${INSTALL_MAN} ${WRKSRC}/doc/updatedb.1 \
		${PREFIX}/${PKGMANDIR}/man1/updatedb.1
	${INSTALL_MAN} ${WRKSRC}/doc/slocate.1 \
		${PREFIX}/${PKGMANDIR}/man1/slocate.1
	${LN} -f -s ${PREFIX}/${PKGMANDIR}/man1/slocate.1 \
		${PREFIX}/${PKGMANDIR}/man1/locate.1
	${INSTALL_DATA_DIR}	${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/updatedb.conf ${EGDIR}/updatedb.conf

.include "../../mk/bsd.pkg.mk"
