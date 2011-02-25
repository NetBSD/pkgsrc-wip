# $NetBSD: Makefile,v 1.1.1.1 2011/02/25 20:14:33 slitvinov Exp $
#

DISTNAME=	ncdu-1.7
CATEGORIES=	filesystems
MASTER_SITES=	http://sourceforge.net/projects/ncdu/files/ncdu/ncdu-1.7/

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://dev.yorhel.nl/ncdu
COMMENT=	Disk usage visualization tool

GNU_CONFIGURE=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
