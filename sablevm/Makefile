# $NetBSD: Makefile,v 1.1.1.1 2004/03/23 23:43:56 poppnk Exp $
#

DISTNAME=		sablevm-1.1.0
CATEGORIES=		wip
MASTER_SITES=		http://devel.sablevm.org/download/1.1.0/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.sablevm.org/
COMMENT=		Free Java Virtual Machine

DEPENDS+=		m4>=1.4:../../devel/m4/

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
NO_BUILDLINK= #

CONFIGURE_ARGS+=	--with-gnu-ld

#.include "../../devel/m4/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/libffi/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
