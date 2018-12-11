# $NetBSD$

DISTNAME=	libxls-1.4.0
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libxls/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ik@sjmulder.nl
HOMEPAGE=	http://libxls.sourceforge.net/
COMMENT=	Extract cell data from legacy Microsoft Excel files
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/libxls

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
