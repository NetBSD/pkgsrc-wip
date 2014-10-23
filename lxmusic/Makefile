# $NetBSD: Makefile,v 1.4 2014/10/23 09:06:41 noud4 Exp $
#

DISTNAME=	lxmusic-0.4.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.org/
COMMENT=	Minimalist XMMS2-based music player
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	none

WRKSRC=		${WRKDIR}/lxmusic-0.4.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl
USE_TOOLS+=	pkg-config

.include "../../wip/xmms2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
