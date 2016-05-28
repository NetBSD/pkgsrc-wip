# $NetBSD: Makefile,v 1.13 2012/10/01 21:57:42 asau Exp $
#

DISTNAME=		kpanta_1_0
PKGNAME=		${DISTNAME:S/_1_0/-1.0/}
WRKSRC=			${WRKDIR}/kpanta
PKGREVISION=		5
CATEGORIES=		games
MASTER_SITES=		http://www.geocities.com/anil_rvce/kpanta/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.geocities.com/anil_rvce/kpanta.html
COMMENT=		AntiChess - like ordinary chess, but the objective is to loose pieces


GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

# propably ${TAR} options include extraction to a specified dir
# look it up in man :)

post-extract:
	${MV} "${WRKDIR}/kpanta - 1.0/" ${WRKDIR}/kpanta

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
