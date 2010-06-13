# $NetBSD: Makefile,v 1.4 2010/06/13 22:47:21 thomasklausner Exp $
#

DISTNAME=	xcowsay-1.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.nickg.me.uk/files/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://www.doof.me.uk/xcowsay/
COMMENT=	Display a cow and message on your desktop
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=			pkg-config

# FIXME: the dbus option doesn't work on NetBSD due a
# pthread_mutex_unlock(3) error (probably this is a devel/glib2 problem
# and it should be fixed).
#.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
