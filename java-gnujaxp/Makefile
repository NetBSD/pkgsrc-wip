# $NetBSD: Makefile,v 1.6 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=		gnujaxp-1.0beta1
PKGNAME=		java-gnujaxp-1.0b1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=classpathx/}
EXTRACT_SUFX=		.zip
LICENSE=		gnu-gpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/classpathx/jaxp/
COMMENT=		XML extensions for GNU classpath


do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/gnujaxp.jar \
		${DESTDIR}${PREFIX}/share/classpath/gnujaxp.jar
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/java-gnujaxp/
	${CP} -rf ${WRKSRC}/apidoc/* \
		${DESTDIR}${PREFIX}/share/doc/java-gnujaxp/

.include "../../mk/bsd.pkg.mk"
