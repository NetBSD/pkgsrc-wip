# $NetBSD$

DISTNAME=	libudev-228
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=gentoo/}
GITHUB_PROJECT=	eudev
GITHUB_TAG=	v3.2.8 # udev version 228 according to configure.ac

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://wiki.gentoo.org/wiki/Project:Eudev
COMMENT=	Device enumeration and database of constants
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=	autoconf automake gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-programs --with-rootrundir=${VARBASE}/run

pre-configure:
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
