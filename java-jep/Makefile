# $NetBSD: Makefile,v 1.1.1.1 2004/03/18 15:38:17 poppnk Exp $
#

DISTNAME=		jep-2.24
CATEGORIES=		wip
MASTER_SITES=		http://www.singularsys.com/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.singularsys.com/
COMMENT=		Java Mathematical Expression Parser

USE_BUILDLINK3=		yes

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/jep-2.24.jar \
		${PREFIX}/share/classpath/jep.jar

.include "../../mk/bsd.pkg.mk"
