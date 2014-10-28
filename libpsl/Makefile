# $NetBSD: Makefile,v 1.2 2014/10/28 15:33:54 thomasklausner Exp $

DISTNAME=	libpsl-0.6.0
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/rockdaboot/libpsl/archive/${PKGVERSION}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rockdaboot/libpsl/
COMMENT=	Library to handle the Public Suffix List
LICENSE=	mit

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
BUILD_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools
BUILD_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc

USE_TOOLS+=	gmake pkg-config autoconf automake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libpsl.pc.in

pre-configure:
	cd ${WRKSRC} && ${CONFIG_SHELL} autogen.sh

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
