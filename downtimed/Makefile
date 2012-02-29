# $NetBSD: Makefile,v 1.6 2012/02/29 19:29:31 errellion Exp $
#

DISTNAME=	downtimed-0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.epipe.com/downtimed/

MAINTAINER=	bartosz@maciejewski.org
HOMEPAGE=	http://dist.epipe.com/downtimed/
COMMENT=	Downtimed is monitoring system downtime
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

BUILD_DEFS+=            VARBASE
OWN_DIRS+=         ${VARBASE}/db/downtimed ${ROOT_USER} ${ROOT_GROUP}
RCD_SCRIPTS+=	downtimed

.include "../../mk/bsd.pkg.mk"
