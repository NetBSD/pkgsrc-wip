# $NetBSD$

DISTNAME=	motion-4.0.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Motion-Project/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lavrsen.dk/foswiki/bin/view/Motion/WebHome
COMMENT=	Motion detecting video camera package
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake bash gmake pkg-config
CONFIG_SHELL=	bash

PKG_SYSCONFSUBDIR=	motion
EGDIR=			${PREFIX}/share/examples
INSTALL_MAKE_FLAGS+=	examplesdir=${EGDIR}/motion
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

.for file in motion camera1 camera2 camera3 camera4
CONF_FILES+=	${EGDIR}/motion/${file}-dist.conf ${PKG_SYSCONFDIR}/${file}.conf
.endfor

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
