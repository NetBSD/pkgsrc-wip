# $NetBSD: Makefile,v 1.1.1.1 2012/03/06 05:19:25 khorben Exp $
#

DISTNAME=	clipit-1.4.1
CATEGORIES=	x11
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clipit/}
MASTER_SITES=	http://sourceforge.net/projects/gtkclipit/files/Version%201/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://clipit.rspwn.com/
COMMENT=	Lightweight, fully featured GTK+ clipboard manager

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

USE_TOOLS+=	gmake
USE_TOOLS+=	intltool


.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
