# $NetBSD: Makefile,v 1.1 2015/08/19 19:36:55 yhardy Exp $

DISTNAME=	opentyrian-2.1.20130907-src
PKGNAME=	opentyrian-2.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.camanis.net/opentyrian/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/opentyrian/opentyrian/wiki/Home
COMMENT=	SDL port of the DOS shoot-em-up Tyrian
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/opentyrian-2.1.20130907

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opentyrian ${DESTDIR}${PREFIX}/bin/opentyrian

.include "options.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
