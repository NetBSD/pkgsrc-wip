# $NetBSD: Makefile,v 1.2 2010/06/03 20:36:26 khorben Exp $

DISTNAME=	Phone-0.0.9
PKGNAME=	deforaos-phone-0.0.9
CATEGORIES=	comms
MASTER_SITES=	http://www.defora.org/os/download/download/3360/

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
