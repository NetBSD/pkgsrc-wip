# $NetBSD: Makefile,v 1.31 2014/10/09 14:06:37 wiz Exp $
#

DISTNAME=	tnt-1.9.2
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.wspse.de/pub/packet_radio/tnt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wspse.de/WSPse/Packet.php3
COMMENT=	Amateur packet radio terminal program for TNC2, AEA PK232 and PK88

DEPENDS+=	dialog>=0.6z:../../misc/dialog

USE_TOOLS+=		gmake
# TNT is K&R-era C; GCC 14 makes implicit-int and
# implicit-function-declaration hard errors by default.
CFLAGS+=	-Wno-error=implicit-int -Wno-error=implicit-function-declaration
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

LDFLAGS.DragonFly+=	-lintl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
