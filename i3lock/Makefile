# $NetBSD: Makefile,v 1.1.1.1 2010/01/04 13:53:51 pallegra Exp $
#

DISTNAME=	i3lock-1.0
CATEGORIES=	x11
MASTER_SITES=	http://i3.zekjur.net/i3lock/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://i3.zekjur.net/i3lock/
COMMENT=	Slightly improved screen locker based on slock
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c99

# print options before building...
MAKE_JOBS_SAFE=	no

SPECIAL_PERMS+=	bin/i3lock ${SETUID_ROOT_PERMS}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
