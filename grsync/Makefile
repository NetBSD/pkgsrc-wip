# $NetBSD: Makefile,v 1.1.1.1 2006/10/04 10:09:40 ondratu Exp $
#

DISTNAME=		grsync-0.5
CATEGORIES=		net
MASTER_SITES=		http://www.opbyte.it/release/

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		http://www.opbyte.it/grsync/
COMMENT=		Grsync is a GUI (Graphical User Interface) for rsync

USE_TOOLS+=		msgfmt pkg-config

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
