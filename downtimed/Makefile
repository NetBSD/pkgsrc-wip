# $NetBSD: Makefile,v 1.1.1.2 2012/02/28 11:34:25 errellion Exp $
#

DISTNAME=	downtimed-0.5
CATEGORIES=	wip
MASTER_SITES=	http://dist.epipe.com/downtimed/

MAINTAINER=	bartosz@maciejewski.org
HOMEPAGE=	http://dist.epipe.com/downtimed/
COMMENT=	Downtimed monitors system downtim
LICENSE=	original-bsd
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"

BUILD_DEFS+=            VARBASE
MAKE_DIRS_PERMS+=         ${VARBASE}/db/downtimed ${ROOT_USER} ${ROOT_GROUP} 0700
