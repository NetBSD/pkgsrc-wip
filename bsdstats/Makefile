# $NetBSD: Makefile,v 1.2 2010/02/26 09:38:08 shindenmorr Exp $
#

DISTNAME=		300.statistics
PKGNAME=		bsdstats-5.3
CATEGORIES=		sysutils misc
MASTER_SITES=		# http://www.bsdstats.org/downloads/
EXTRACT_SUFX=

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://www.bsdstats.org/
COMMENT=		BSD-Stats collector script

DEPENDS+=		netcat-[0-9]*:../../net/netcat

PKG_DESTDIR_SUPPORT=	user-destdir

# XXX: Others might work
ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-* FreeBSD-*-* OpenBSD-*-*

BUILD_DEFS+=            VARBASE

NO_BUILD=		yes

MESSAGE_SUBST+=		PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${VARBASE}/db/bsdstats

do-install:
	${INSTALL} ${FILESDIR}/300.statistics ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
