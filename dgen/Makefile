# $NetBSD: Makefile,v 1.4 2003/09/22 20:31:47 xtraeme Exp $
#

DISTNAME=	dgen-sdl-1.23
CATEGORIES=	emulators
MASTER_SITES=	http://www.pknet.com/~joe/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.pknet.com/~joe/dgen-sdl.html
COMMENT=	Genesis/Megadrive emulator for Unix platforms

.if ${MACHINE_ARCH} == "i386"
DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes
USE_BUILDLINK2=	yes

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
