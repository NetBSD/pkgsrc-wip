# $NetBSD: Makefile,v 1.8 2006/05/19 16:51:26 ykomatsu Exp $
#

DISTNAME=	# empty
PKGNAME=	mupen64-0.3
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 meta-package

DEPENDS=	mupen64-base>=0.3:../../wip/mupen64-base
DEPENDS+=	mupen64-plugin-input-[0-9]*:../../wip/mupen64-plugin-input
DEPENDS+=	mupen64-plugin-rsp-[0-9]*:../../wip/mupen64-plugin-rsp
DEPENDS+=	mupen64-plugin-sound-[0-9]*:../../wip/mupen64-plugin-sound
DEPENDS+=	mupen64-plugin-video-[0-9]*:../../wip/mupen64-plugin-video

NO_BUILD=	yes
NO_CHECKSUM=	yes
NO_MTREE=	yes
NO_CONFIGURE=	yes

do-install:
	# empty

.include "../../mk/bsd.pkg.mk"
