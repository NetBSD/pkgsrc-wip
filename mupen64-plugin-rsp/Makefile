# $NetBSD: Makefile,v 1.2 2004/05/07 01:58:12 xtraeme Exp $
#

DISTNAME=	mupen64_hle_rsp
PKGNAME=	${DISTNAME:S/_hle_rsp/-plugin-rsp-1.1/}
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
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
