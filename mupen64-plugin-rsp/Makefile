# $NetBSD: Makefile,v 1.8 2006/09/14 18:18:58 dhowland Exp $
#

DISTNAME=	hack_azi_rsp_hle
PKGNAME=	${DISTNAME:S/hack_azi_rsp_hle/mupen64-plugin-rsp-1.2/}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/0.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	RSP plugin for mupen64 emulator

BUILD_DEPENDS+=	mupen64-base-[0-9]*:../../wip/mupen64-base

USE_LANGUAGES=	c c++

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
