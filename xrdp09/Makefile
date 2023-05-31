# $NetBSD$

DISTNAME=		xrdp-0.9.22.1
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_GITHUB:=neutrinolabs/}
GITHUB_PROJECT=		xrdp
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		https://www.xrdp.org/
COMMENT=		Remote Desktop Protocol server
LICENSE=		apache-2.0

USE_TOOLS+=		autoconf automake gmake pkg-config
USE_LIBTOOL=		yes
DL_AUTO_VARS=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-painter
CONFIGURE_ARGS+=	--disable-rfxcodec

RCD_SCRIPTS=		xrdp sesman
RCD_SCRIPT_SRC.xrdp=	files/xrdp.sh
RCD_SCRIPT_SRC.sesman=	files/sesman.sh

AUTO_MKDIRS=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

post-configure:
	cd ${WRKSRC} && \
		${CP} xrdp_configure_options.h xrdp_configure_options.h.orig && \
		${AWK} '/PKG_CONFIG/{ next } //' xrdp_configure_options.h.orig >xrdp_configure_options.h

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
