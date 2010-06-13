# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:05 thomasklausner Exp $
#

DISTNAME=		godura-0.6.2
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		http://www.mindspring.com/~joeja/ftp/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://home.earthlink.net/~joseph-ja/programs.html
COMMENT=		Simple GTK2-based notepad text editor

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
