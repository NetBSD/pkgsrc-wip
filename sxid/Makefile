# $NetBSD: Makefile,v 1.2 2006/10/30 22:45:31 shattered Exp $
#

DISTNAME=		sxid_4.0.4
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.phunnypharm.org/pub/sxid/

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.phunnypharm.org/pub/sxid/
COMMENT=		Suid, sgid file and directory checking

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/sxid
CONF_FILES=		${EGDIR}/sxid.conf ${PKG_SYSCONFDIR}/sxid.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/sxid.conf.example ${EGDIR}/sxid.conf

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
