# $NetBSD: Makefile,v 1.11 2012/12/27 06:04:19 othyro Exp $
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
CPPFLAGS+=	-fPIC

INSTALLATION_DIRS+=	share/mupen64-base/plugins

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
