# $NetBSD: Makefile,v 1.4 2012/10/01 20:19:36 asau Exp $
#

DISTNAME=		decimal
PKGNAME=		java-BigDecimal-1.0
CATEGORIES=		devel math
MASTER_SITES=		http://www2.hursley.ibm.com/decimalj/
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www2.hursley.ibm.com/decimalj/
COMMENT=		Decimal arithmetic for Java

WRKSRC=			${WRKDIR}/

INSTALLATION_DIRS=	share/classpath

do-build:

do-install:
	${INSTALL_DATA} ${WRKDIR}/decimal.jar \
		${DESTDIR}${PREFIX}/share/classpath/

.include "../../mk/bsd.pkg.mk"
