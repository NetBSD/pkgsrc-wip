# $NetBSD: Makefile,v 1.2 2004/05/08 14:22:32 poppnk Exp $
#

DISTNAME=		gnujaxp-1.0beta1
PKGNAME=		java-gnujaxp-1.0b1
CATEGORIES=		wip devel
MASTER_SITES=		${MASTER_SITE_GNU:=classpathx/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gnu.org/software/classpathx/jaxp/
COMMENT=		XML extensions for GNU classpath

USE_BUILDLINK3=		yes

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/gnujaxp.jar \
		${PREFIX}/share/classpath/gnujaxp.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java-gnujaxp/
	${CP} -rf ${WRKSRC}/apidoc/* \
		${PREFIX}/share/doc/java-gnujaxp/

.include "../../mk/bsd.pkg.mk"
