# $NetBSD: Makefile,v 1.3 2005/04/11 21:13:19 tvierling Exp $
#

DISTNAME=		jflex_small-1.3.5
PKGNAME=		java-jflex-1.3.5
CATEGORIES=		wip textproc
MASTER_SITES=		http://www.jflex.de/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.jflex.de/
COMMENT=		The Fast Scanner Generator for Java

WRKSRC=		${WRKDIR}/JFlex

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/JFlex.jar \
		${PREFIX}/share/classpath/

.include "../../mk/bsd.pkg.mk"
