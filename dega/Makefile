# $NetBSD: Makefile,v 1.1.1.1 2003/08/24 23:57:53 poppnk Exp $
#

DISTNAME=	dega-1.07
CATEGORIES=	emulators
MASTER_SITES=	http://www.emulinks.de/emus/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.finalburn.com/dega/ \
		http://www.emulinks.de/emus/
COMMENT=	GameGear and MasterSystem emulator

USE_GMAKE=	yes
USE_X11=	yes
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dega ${PREFIX}/bin

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
