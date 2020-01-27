# $Id: Makefile,v 1.8 2014/10/31 12:45:46 bartoszkuzma Exp $
#

DISTNAME=	downtimed-0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.epipe.com/downtimed/

MAINTAINER=	bartosz@maciejewski.org
HOMEPAGE=	https://dist.epipe.com/downtimed/
COMMENT=	Downtimed is monitoring system downtime
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

BUILD_DEFS+=	VARBASE
OWN_DIRS+=	${VARBASE}/db/downtimed ${ROOT_USER} ${ROOT_GROUP}
RCD_SCRIPTS+=	downtimed

.include "../../mk/bsd.pkg.mk"
