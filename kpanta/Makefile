# $NetBSD: Makefile,v 1.4 2005/07/27 16:25:56 thomasklausner Exp $
#

DISTNAME=		kpanta_1_0
PKGNAME=		${DISTNAME:S/_1_0/-1.0/}
WRKSRC=			${WRKDIR}/kpanta
CATEGORIES=		games
MASTER_SITES=		http://www.geocities.com/anil_rvce/kpanta/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.geocities.com/anil_rvce/kpanta.html
COMMENT=		AntiChess - like ordinary chess, but the objective is to loose pieces

GNU_CONFIGURE=		# defined

# propably ${TAR} options include extraction to a specified dir
# look it up in man :)

post-extract:
	${MV} "${WRKDIR}/kpanta - 1.0/" ${WRKDIR}/kpanta

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
