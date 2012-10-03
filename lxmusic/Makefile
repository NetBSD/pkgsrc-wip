# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:45 asau Exp $
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

.include "../../mk/bsd.pkg.mk"
