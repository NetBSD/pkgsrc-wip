# $NetBSD: Makefile,v 1.6 2012/12/15 16:31:52 slitvinov Exp $
#

DISTNAME=	ncdu-1.9
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ncdu/}

COMMENT=	Disk usage visualization tool
LICENSE=	modified-bsd

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://dev.yorhel.nl/ncdu

GNU_CONFIGURE=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
