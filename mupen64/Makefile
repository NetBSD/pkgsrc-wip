# $NetBSD: Makefile,v 1.9 2008/07/11 03:37:09 dillo Exp $
#

DISTNAME=	# empty
PKGNAME=	mupen64-0.3
CATEGORIES=	meta-pkgs emulators
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mupen64.emulation64.com/
COMMENT=	Free Nintendo 64(TM) emulator for unix-like OS
LICENSE=	gnu-gpl-v2

META_PACKAGE=	yes

DEPENDS=	mupen64-base>=0.3:../../wip/mupen64-base
DEPENDS+=	mupen64-plugin-input-[0-9]*:../../wip/mupen64-plugin-input
DEPENDS+=	mupen64-plugin-rsp-[0-9]*:../../wip/mupen64-plugin-rsp
DEPENDS+=	mupen64-plugin-sound-[0-9]*:../../wip/mupen64-plugin-sound
DEPENDS+=	mupen64-plugin-video-[0-9]*:../../wip/mupen64-plugin-video

.include "../../mk/bsd.pkg.mk"
