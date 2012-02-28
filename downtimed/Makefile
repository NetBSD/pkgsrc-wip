# $NetBSD: Makefile,v 1.5 2012/02/28 14:09:14 errellion Exp $
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

BUILD_DEFS+=            VARBASE
OWN_DIRS+=         ${VARBASE}/db/downtimed ${ROOT_USER} ${ROOT_GROUP}
RCD_SCRIPTS+=	downtimed

.include "../../mk/bsd.pkg.mk"
