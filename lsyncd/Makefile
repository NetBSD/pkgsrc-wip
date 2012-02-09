# $NetBSD: Makefile,v 1.1.1.1 2012/02/09 08:59:57 slitvinov Exp $
#

DISTNAME=	lsyncd-2.0.5
CATEGORIES=	net
MASTER_SITES=	http://lsyncd.googlecode.com/files/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://code.google.com/p/lsyncd/
COMMENT=	Live syncing daemon
LICENSE=	gnu-gpl-v2

DEPENDS+=		rsync-[0-9]*:../../net/rsync
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

# Uses inotify
ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
