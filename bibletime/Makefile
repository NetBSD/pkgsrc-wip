# $NetBSD: Makefile,v 1.1 2014/12/19 21:26:27 nros Exp $

DISTNAME=	bibletime-2.10.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bibletime/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bibletime.info/
COMMENT=	Bible study program based on SWORD and QT
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../wip/sword/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
