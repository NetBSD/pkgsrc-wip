# $NetBSD: Makefile,v 1.11 2012/10/07 15:25:14 asau Exp $
#

DISTNAME=		slocate-3.1
CATEGORIES=		sysutils
MASTER_SITES=	http://slocate.trakker.ca/files/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://slocate.trakker.ca/
COMMENT=		Secure Locate

PKG_DESTDIR_SUPPORT=	destdir

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
	${INSTALL_PROGRAM} ${WRKSRC}/src/slocate ${DESTDIR}${PREFIX}/bin/
	${CHOWN} ${ROOT_USER}:${SLOCATE_GROUP} ${DESTDIR}${PREFIX}/bin/slocate
	${CHMOD} 2755 ${DESTDIR}${PREFIX}/bin/slocate
	${LN} -f -s ${PREFIX}/bin/slocate ${DESTDIR}${PREFIX}/bin/locate
	${LN} -f -s ${PREFIX}/bin/slocate ${DESTDIR}${PREFIX}/bin/updatedb
	${INSTALL_MAN} ${WRKSRC}/doc/updatedb.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/updatedb.1
	${INSTALL_MAN} ${WRKSRC}/doc/slocate.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/slocate.1
	${LN} -f -s ${PREFIX}/${PKGMANDIR}/man1/slocate.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/locate.1
	${INSTALL_DATA_DIR}	${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/updatedb.conf ${DESTDIR}${EGDIR}/updatedb.conf

.include "../../mk/bsd.pkg.mk"
