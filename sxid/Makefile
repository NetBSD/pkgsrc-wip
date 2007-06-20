# $NetBSD: Makefile,v 1.3 2007/06/20 13:29:49 bartoszkuzma Exp $
#

DISTNAME=		sxid_4.0.4
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.phunnypharm.org/pub/sxid/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://www.phunnypharm.org/pub/sxid/
COMMENT=		Suid, sgid file and directory checking

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/sxid
CONF_FILES=		${EGDIR}/sxid.conf ${PKG_SYSCONFDIR}/sxid.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/sxid ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/sxid.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/docs/sxid.conf.5 ${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/sxid.conf.example ${EGDIR}/sxid.conf

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
