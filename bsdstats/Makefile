# $NetBSD: Makefile,v 1.3 2010/03/08 21:21:23 shindenmorr Exp $
#

DISTNAME=		300.statistics
PKGNAME=		bsdstats-5.3
CATEGORIES=		sysutils misc
MASTER_SITES=		# http://www.bsdstats.org/downloads/
DISTFILES=		# empty

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://www.bsdstats.org/
COMMENT=		BSD-Stats collector script

DEPENDS+=		netcat-[0-9]*:../../net/netcat

PKG_DESTDIR_SUPPORT=	user-destdir

# XXX: Others might work
ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-* FreeBSD-*-* OpenBSD-*-*

BUILD_DEFS+=		VARBASE

WRKSRC=			${WRKDIR}/bsdstats

NO_BUILD=		yes

MESSAGE_SUBST+=		PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${VARBASE}/db/bsdstats

post-extract:
	${MKDIR} ${WRKDIR}/bsdstats
	${SED} -e "s!@PREFIX@!${PREFIX}!g" ${FILESDIR}/300.statistics \
		> ${WRKSRC}/300.statistics

do-install:
	${INSTALL} ${WRKSRC}/300.statistics ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
