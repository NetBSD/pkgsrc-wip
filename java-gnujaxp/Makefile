# $NetBSD: Makefile,v 1.1.1.1 2004/03/09 00:23:51 poppnk Exp $
#

DISTNAME=		gnujaxp-1.0beta1
PKGNAME=		java-gnujaxp-1.0b1
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_GNU:=classpathx/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gnu.org/software/classpathx/jaxp/
COMMENT=		XML extensions for GNU classpath

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/gnujaxp.jar \
		${PREFIX}/share/classpath/gnujaxp.jar

.include "../../mk/bsd.pkg.mk"
