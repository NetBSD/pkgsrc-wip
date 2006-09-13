# $NetBSD: Makefile,v 1.1.1.1 2006/09/13 13:56:57 bartoszkuzma Exp $
#

DISTNAME=		sxid_4.0.4
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.phunnypharm.org/pub/sxid/

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.phunnypharm.org/pub/sxid/
COMMENT=		Suid, sgid file and directory checking

WRKSRC=			${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/sxid
CONF_FILES=		${EGDIR}/sxid.conf ${PKG_SYSCONFDIR}/sxid.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/sxid.conf.example ${EGDIR}/sxid.conf

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
