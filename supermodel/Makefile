# $NetBSD: Makefile,v 1.1 2012/11/26 19:46:21 othyro Exp $
#

DISTNAME=	Supermodel_0.2a_Src
PKGNAME=	${DISTNAME:tl:S/_src//1:S/_/-/1}
CATEGORIES=	emulators
MASTER_SITES=	http://www.supermodel3.com/Files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.supermodel3.com/
COMMENT=	Sega Model 3 Arcade Emulator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FILE=		Makefiles/Makefile.SDL.UNIX.GCC
INSTALLATION_DIRS+=	bin

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} bin/Supermodel ${DESTDIR}${PREFIX}/bin/Supermodel

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
