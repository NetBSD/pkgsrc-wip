# $NetBSD: Makefile,v 1.3 2005/04/11 21:13:18 tvierling Exp $
#

DISTNAME=		gnujaxp-1.0beta1
PKGNAME=		java-gnujaxp-1.0b1
CATEGORIES=		wip devel
MASTER_SITES=		${MASTER_SITE_GNU:=classpathx/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gnu.org/software/classpathx/jaxp/
COMMENT=		XML extensions for GNU classpath


do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/gnujaxp.jar \
		${PREFIX}/share/classpath/gnujaxp.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java-gnujaxp/
	${CP} -rf ${WRKSRC}/apidoc/* \
		${PREFIX}/share/doc/java-gnujaxp/

.include "../../mk/bsd.pkg.mk"
