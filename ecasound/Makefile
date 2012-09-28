# $NetBSD: Makefile,v 1.5 2012/09/28 22:07:29 asau Exp $
#

DISTNAME=		ecasound-2.4.1
CATEGORIES=		audio
MASTER_SITES=		http://ecasound.seul.org/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ecasound.seul.org/
COMMENT=		Multitrack audio processor

PKG_DESTDIR_SUPPORT=	none

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_NCURSES=		yes # term.h, setupterm(), ...

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
