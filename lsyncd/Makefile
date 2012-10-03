# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:43 asau Exp $
#

DISTNAME=	lsyncd-2.0.5
CATEGORIES=	net
MASTER_SITES=	http://lsyncd.googlecode.com/files/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://code.google.com/p/lsyncd/
COMMENT=	Live syncing daemon
LICENSE=	gnu-gpl-v2

DEPENDS+=		rsync-[0-9]*:../../net/rsync

USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

# Uses inotify
ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
