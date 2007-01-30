# $NetBSD: Makefile,v 1.1.1.1 2007/01/30 16:56:58 netcap Exp $
#

DISTNAME=	drumpiler-0.9.0
CATEGORIES=	audio
MASTER_SITES= ${MASTER_SITE_SOURCEFORGE:=drumpiler/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://drumpiler.sourceforge.net/
COMMENT=	Drum machine compiler

BUILD_DEPENDS+=		SDL-1.2.[0-9]*:../../devel/SDL

SDL_CONFIG=	${PREFIX}/bin/sdl-config
CFLAGS+=	`${SDL_CONFIG} --cflags`
LIBS+=		`${SDL_CONFIG} --libs`

do-build:
		cd ${WRKSRC} && ${CC} ${CFLAGS} -DUSESDL -o drumpiler drumpiler.c ${LIBS}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/drumpiler ${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
