# $NetBSD: Makefile,v 1.1 2015/01/24 14:27:04 gschwarz Exp $

DISTNAME=	ophcrack-3.8.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ophcrack/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://ophcrack.sourceforge.io/
COMMENT=	Ophcrack is a free Windows password cracker based on rainbow tables
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtcharts/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libssl=${SSLBASE:Q}
.include "../../mk/bsd.pkg.mk"
