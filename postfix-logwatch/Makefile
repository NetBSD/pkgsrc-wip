# $NetBSD: Makefile,v 1.1 2013/07/01 11:41:44 noud4 Exp $
#

DISTNAME=	${FILTER_NAME}-1.40.00
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=logreporters/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://logreporters.sourceforge.net/
COMMENT=	Postfix log reporting utility
LICENSE=	mit

FILTER_NAME=	postfix-logwatch

.include "options.mk"

.include "../../wip/postfix-logwatch/Makefile.common"

.include "../../mk/bsd.pkg.mk"
