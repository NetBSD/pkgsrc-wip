# $NetBSD: Makefile,v 1.2 2004/04/17 00:10:36 xtraeme Exp $
#

DISTNAME=	# empty
PKGNAME=	mupen64-0.3
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 meta-package

DEPENDS=	mupen64-base>=0.3:../mupen64-base
DEPENDS+=	mupen64-plugin-input-[0-9]*:../mupen64-plugin-input
DEPENDS+=	mupen64-plugin-rsp-[0-9]*:../mupen64-plugin-rsp
DEPENDS+=	mupen64-plugin-sound-[0-9]*:../mupen64-plugin-sound
DEPENDS+=	mupen64-plugin-video-[0-9]*:../mupen64-plugin-video

NO_BUILD=		# defined
NO_BUILDLINK=		# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_CONFIGURE=		# defined

do-install:
	# empty

.include "../../mk/bsd.pkg.mk"
