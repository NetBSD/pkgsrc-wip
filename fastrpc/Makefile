# $NetBSD: Makefile,v 1.4 2012/11/12 15:59:48 othyro Exp $
#

DISTNAME=	fastrpc-1.0.13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fastrpc/}
LICENSE=	gnu-lgpl-v2

MAINTAINER=	ondrej.tuma@firma.seznam.cz
HOMEPAGE=	https://downloads.sourceforge.net/sourceforge/fastrpc/
COMMENT=	Protocol based on the XML-RPC which uses binary format for data

WRKSRC=		${WRKDIR}/fastrpc-1.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
