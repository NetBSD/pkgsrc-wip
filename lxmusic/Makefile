# $NetBSD: Makefile,v 1.5 2014/10/23 11:19:39 noud4 Exp $
#

DISTNAME=	lxmusic-0.4.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.org/
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
