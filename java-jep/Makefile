# $NetBSD: Makefile,v 1.3 2004/04/18 17:07:15 poppnk Exp $
#

DISTNAME=		jep-2.24
PKGNAME=		java-jep-2.24
CATEGORIES=		wip
MASTER_SITES=		http://www.singularsys.com/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.singularsys.com/jep/
COMMENT=		Java Mathematical Expression Parser

USE_BUILDLINK3=		yes

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/jep-2.24.jar \
		${PREFIX}/share/classpath/jep.jar

.include "../../mk/bsd.pkg.mk"
