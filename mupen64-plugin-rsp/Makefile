# $NetBSD: Makefile,v 1.1.1.1 2004/04/16 22:31:02 xtraeme Exp $
#

DISTNAME=	mupen64_hle_rsp
PKGNAME=	${DISTNAME:S/_hle_rsp/-plugin-rsp-1.1/}
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	RSP plugin for mupen64 emulator

USE_BUILDLINK3=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/rsp_hle

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
