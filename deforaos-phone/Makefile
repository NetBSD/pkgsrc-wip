# $NetBSD: Makefile,v 1.10 2011/12/14 23:46:39 khorben Exp $

DISTNAME=	Phone-0.3.8
PKGNAME=	deforaos-phone-0.3.8
CATEGORIES=	comms
MASTER_SITES=	http://www.defora.org/os/download/download/3603/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS telephony application

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "options.mk"

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../wip/deforaos-locker/buildlink3.mk"
.include "../../wip/sofia-sip/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
