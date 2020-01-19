# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:10 noud4 Exp $
#

DISTNAME=	${FILTER_NAME}-1.40.00
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=logreporters/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	https://logreporters.sourceforge.net/
COMMENT=	Postfix log reporting utility
LICENSE=	mit

FILTER_NAME=	postfix-logwatch

.include "options.mk"

.include "../../wip/postfix-logwatch/Makefile.common"

.include "../../mk/bsd.pkg.mk"
