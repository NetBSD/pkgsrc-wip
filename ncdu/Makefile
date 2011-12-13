# $NetBSD: Makefile,v 1.3 2011/12/13 17:29:17 slitvinov Exp $
#

DISTNAME=	ncdu-1.8
CATEGORIES=	filesystems
MASTER_SITES=	http://sourceforge.net/projects/ncdu/files/ncdu/ncdu-1.8/

COMMENT=	Disk usage visualization tool
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://dev.yorhel.nl/ncdu

GNU_CONFIGURE=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
