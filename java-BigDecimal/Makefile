# $NetBSD: Makefile,v 1.2 2004/07/18 15:50:23 ppostma Exp $
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
USE_BUILDLINK3=		yes

do-build:

do-install:
	${INSTALL_DATA} ${WRKDIR}/decimal.jar \
		${PREFIX}/share/classpath/

.include "../../mk/bsd.pkg.mk"
