# $NetBSD: Makefile,v 1.1 2015/04/19 23:36:03 nbrkv Exp $
#

DISTNAME=		dunelegacy-0.96.2-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dunelegacy/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dunelegacy.sourceforge.net/
COMMENT=		Open-source Dune 2 clone
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
