# $NetBSD: Makefile,v 1.1 2015/06/03 00:38:05 mbowie Exp $

DISTNAME=	owamp-3.4-10
CATEGORIES=	net
MASTER_SITES=	http://software.internet2.edu/sources/owamp/

MAINTAINER=	mbowie@rocketspace.com
HOMEPAGE=	http://software.internet2.edu/owamp/
COMMENT=	One-way active measurement protocol
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/owamp-3.4
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-I2util=${BUILDLINK_PREFIX.I2util}

.include "../../wip/I2util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
