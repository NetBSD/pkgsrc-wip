# $NetBSD: Makefile,v 1.6 2015/05/21 19:24:26 blef Exp $

DISTNAME=	lxmusic-0.4.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxde.org/
COMMENT=	Minimalist XMMS2-based music player
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl
USE_TOOLS+=	pkg-config

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/xmms2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
