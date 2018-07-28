# $NetBSD: Makefile,v 1.2 2014/10/28 15:33:54 thomasklausner Exp $

DISTNAME=	libpsl-0.20.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rockdaboot/}
GITHUB_RELEASE=	${DISTNAME}
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	${DEFAULT_DISTFILES} public_suffix_list.dat
SITES.public_suffix_list.dat=	https://raw.githubusercontent.com/publicsuffix/list/c45eff1c741d197778430e64e5d6f8bb0d7e9c8d/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rockdaboot/libpsl/
COMMENT=	Library to handle the Public Suffix List
LICENSE=	mit

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
BUILD_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools

USE_TOOLS+=	gmake pkg-config autoconf automake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libpsl.pc.in

pre-configure:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/public_suffix_list.dat ${WRKSRC}/list/
	cd ${WRKSRC} && ${CONFIG_SHELL} autogen.sh

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
