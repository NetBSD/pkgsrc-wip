# $NetBSD: Makefile,v 1.7 2012/09/28 21:24:37 asau Exp $
#

DISTNAME=	downtimed-0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.epipe.com/downtimed/

MAINTAINER=	bartosz@maciejewski.org
HOMEPAGE=	http://dist.epipe.com/downtimed/
COMMENT=	Downtimed is monitoring system downtime
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

BUILD_DEFS+=            VARBASE
OWN_DIRS+=         ${VARBASE}/db/downtimed ${ROOT_USER} ${ROOT_GROUP}
RCD_SCRIPTS+=	downtimed

.include "../../mk/bsd.pkg.mk"
