# $NetBSD: Makefile,v 1.1.1.1 2004/03/17 20:10:59 poppnk Exp $
#

DISTNAME=		jflex_small-1.3.5
PKGNAME=		java-jflex-1.3.5
CATEGORIES=		wip textproc
MASTER_SITES=		http://www.jflex.de/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.jflex.de/
COMMENT=		The Fast Scanner Generator for Java

WRKSRC=		${WRKDIR}/JFlex
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/JFlex.jar \
		${PREFIX}/share/classpath/

.include "../../mk/bsd.pkg.mk"
