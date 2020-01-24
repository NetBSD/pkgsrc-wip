# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:08 noud4 Exp $
#

DISTNAME=	${FILTER_NAME}-1.51.02
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=logreporters/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://logreporters.sourceforge.net/
COMMENT=	Amavis log reporting utility
LICENSE=	mit

FILTER_NAME=	amavis-logwatch

.include "options.mk"

.include "../../wip/postfix-logwatch/Makefile.common"

.include "../../mk/bsd.pkg.mk"
