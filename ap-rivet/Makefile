# $NetBSD: Makefile,v 1.2 2004/12/11 04:15:22 minskim Exp $

DISTNAME=	rivet_0.4.0-1
PKGNAME=	ap-rivet-0.4.0.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE:=tcl/rivet/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://tcl.apache.org/rivet/
COMMENT=	System for creating dynamic web content via Tcl

WRKSRC=		${WRKDIR}/tcl-rivet/src
HAS_CONFIGURE=	yes
USE_BUILDLINK3=	yes

CONFIGURE_SCRIPT=	./configure.tcl
CONFIGURE_ARGS+=	-prefix ${PREFIX}/lib				\
			-with-apxs ${APXS}				\
			-with-tclconfig ${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
CONFIGURE_ENV+=		LANG=C

do-install:
	cd ${WRKSRC}; ./make.tcl install

.include "../../lang/tcl/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
