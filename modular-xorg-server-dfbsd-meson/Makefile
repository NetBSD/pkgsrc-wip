# $NetBSD: Makefile,v 1.117 2018/10/26 10:20:12 maya Exp $

DISTNAME=	xorg-server-${XORG_VERSION}
PKGNAME=	modular-${DISTNAME}
# PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modular X11 server from modular X.org

SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}

NOT_FOR_PLATFORM=	Darwin-*-*

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-xorg
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-kdrive
CONFIGURE_ARGS.SunOS+=	--disable-input-thread
# MESON_ARGS+=	-Dxorg=true
MESON_ARGS+=	-Dxephyr=false
.if ${OPSYS} == "SunOS"
MESON_ARGS+=	-Dinput_thread=false
.endif

.include "options.mk"

# Autotools
# pre-configure:
#	cd ${WRKSRC} && autoreconf -vif

# Meson
.include "../../devel/py-meson/build.mk"

.include "../../mk/bsd.pkg.mk"
