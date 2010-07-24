# $NetBSD: Makefile,v 1.4 2010/07/24 17:38:15 khorben Exp $

DISTNAME=	Phone-0.1.0
PKGNAME=	deforaos-phone-0.1.0
CATEGORIES=	comms
MASTER_SITES=	http://www.defora.org/os/download/download/3373/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop phone

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CPPFLAGS="-D PREFIX=\\\"${PREFIX}\\\""

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
