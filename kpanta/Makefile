# $NetBSD: Makefile,v 1.2 2004/04/26 02:40:21 blef Exp $
#

DISTNAME=		kpanta_1_0
PKGNAME=		${DISTNAME:S/_1_0/-1.0/}
WRKSRC=			${WRKDIR}/kpanta
CATEGORIES=		games
MASTER_SITES=		http://www.geocities.com/anil_rvce/kpanta/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.geocities.com/anil_rvce/kpanta.html
COMMENT=		AntiChess - like ordinary chess, but the objective is to loose pieces

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined

# propably ${TAR} options include extraction to a specified dir
# look it up in man :)

post-extract:
	${MV} "${WRKDIR}/kpanta - 1.0/" ${WRKDIR}/kpanta

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
