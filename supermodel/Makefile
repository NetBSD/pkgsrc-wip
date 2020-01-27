# $NetBSD: Makefile,v 1.2 2012/12/20 14:31:59 othyro Exp $
#

DISTNAME=	Supermodel_0.2a_Src
PKGNAME=	${DISTNAME:tl:S/_src//1:S/_/-/1}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.supermodel3.com/Files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.supermodel3.com/
COMMENT=	Sega Model 3 Arcade Emulator
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
MAKE_FILE=		Makefiles/Makefile.SDL.UNIX.GCC
INSTALLATION_DIRS+=	bin

do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} bin/Supermodel ${DESTDIR}${PREFIX}/bin/Supermodel

BUILD_DEPENDS+=		glu-[0-9]*:../../graphics/glu
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
BUILD_DEPENDS+=		MesaLib-[0-9]*:../../graphics/MesaLib
.include "../../mk/bsd.pkg.mk"
