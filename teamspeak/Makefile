# $NetBSD: Makefile,v 1.2 2005/06/13 00:09:13 kristerw Exp $
#

DISTNAME=		ts2_client_rc2_2032
PKGNAME=		teamspeak-2.0.2032
CATEGORIES=		net audio
MASTER_SITES=		ftp://ftp.freenet.de/pub/4players/teamspeak.org/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		ftp://ftp.freenet.de/pub/4players/teamspeak.org/releases/
COMMENT=		Talk to other people over the internet

NO_BUILD=		yes
LICENSE=		fee-based-commercial-use

SUBST_CLASSES+=		ts
SUBST_STAGE.ts=		post-configure
SUBST_FILES.ts+=	teamspeak.sh
SUBST_SED.ts+=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.ts+=		-e 's|@SH@|${SH}|g'
SUBST_SED.ts+=		-e 's|@PKGNAME@|${PKGNAME}|g'

TS_BASEDIR=		${PREFIX}/lib/${PKGNAME}
TS_SRCDIR=		${WRKSRC}/setup.data/image

do-configure:
	${CP} ${FILESDIR}/teamspeak.sh.in ${WRKSRC}/teamspeak.sh

do-install:
	${INSTALL_DATA_DIR} ${TS_BASEDIR}
	cd ${TS_SRCDIR} && ${PAX} -rw . ${TS_BASEDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/teamspeak.sh ${PREFIX}/bin/teamspeak

.include "../../mk/bsd.pkg.mk"
