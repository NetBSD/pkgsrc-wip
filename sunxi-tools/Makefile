# $NetBSD: Makefile,v 1.1 2015/06/11 20:47:30 tnn2 Exp $

MASTER_SITES=	https://github.com/linux-sunxi/
DISTNAME=	sunxi-tools-1.2
CATEGORIES=	sysutils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/linux-sunxi/sunxi-tools
COMMENT=	Tools for hacking Allwinner Axx (sunxi) based devices
LICENSE=	gnu-gpl-v2

USE_TOOLS=	gmake

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

INSTALLATION_DIRS=	bin

do-install:
.for f in fexc bin2fex fex2bin fel pio nand-part
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
