# $NetBSD: Makefile,v 1.3 2004/05/07 01:58:12 xtraeme Exp $
#

DISTNAME=	mupen64_input
PKGNAME=	${DISTNAME:S/_input/-plugin-input-1.1/}
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	Input plugin for mupen64 emulator

BUILD_DEPENDS+=	mupen64-base-[0-9]*:../wip/mupen64-base

USE_BUILDLINK3=	yes
USE_X11=	yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
