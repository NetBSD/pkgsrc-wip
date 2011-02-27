# $NetBSD: Makefile,v 1.2 2011/02/27 08:33:49 slitvinov Exp $
#

DISTNAME=	ncdu-1.7
CATEGORIES=	filesystems
MASTER_SITES=	http://sourceforge.net/projects/ncdu/files/ncdu/ncdu-1.7/

COMMENT=	Disk usage visualization tool
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://dev.yorhel.nl/ncdu

GNU_CONFIGURE=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
