# $NetBSD: Makefile,v 1.7 2012/10/07 16:38:04 asau Exp $

DISTNAME=		ts2_client_rc2_2032
PKGNAME=		teamspeak-2.0.2032
CATEGORIES=		net audio
MASTER_SITES=		#
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		ftp://ftp.freenet.de/pub/4players/teamspeak.org/releases/
COMMENT=		Talk to other people over the internet
LICENSE=		fee-based-commercial-use

NO_BUILD=		yes
USE_TOOLS+=		pax

SUBST_CLASSES+=		ts
SUBST_STAGE.ts=		post-configure
SUBST_FILES.ts+=	teamspeak.sh
SUBST_SED.ts+=		-e 's|@BASEDIR@|${TS_BASEDIR}|g'
SUBST_VARS.ts=		SH

TS_BASEDIR=		${PREFIX}/lib/${PKGNAME_NOREV}
TS_SRCDIR=		${WRKSRC}/setup.data/image

do-configure:
	${CP} ${FILESDIR}/teamspeak.sh.in ${WRKSRC}/teamspeak.sh

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${TS_BASEDIR}
	cd ${TS_SRCDIR} && pax -rw . ${DESTDIR}${TS_BASEDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/teamspeak.sh ${DESTDIR}${PREFIX}/bin/teamspeak

.include "../../mk/bsd.pkg.mk"
