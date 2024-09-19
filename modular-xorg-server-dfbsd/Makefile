# $NetBSD: Makefile,v 1.119 2019/07/20 22:46:57 wiz Exp $

DISTNAME=	xorg-server-${XORG_VERSION}
PKGNAME=	modular-${DISTNAME}
# DISTNAME=	xorg-server-${XORG_VERSION}
# PKGNAME=	modular-xorg-server-${XORG_VERSION}
# PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modular X11 server from modular X.org

SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}

post-install:
	${LN} -sf ${PREFIX}/bin/Xorg ${DESTDIR}${PREFIX}/bin/X

NOT_FOR_PLATFORM=	Darwin-*-*

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-xorg
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-kdrive
CONFIGURE_ARGS.SunOS+=	--disable-input-thread
MESON_ARGS+=		-Dxorg=true
MESON_ARGS+=		-Dxephyr=false
.if ${OPSYS} == "SunOS"
MESON_ARGS+=		-Dinput_thread=false
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
