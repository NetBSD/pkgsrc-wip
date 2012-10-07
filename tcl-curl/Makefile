# $NetBSD: Makefile,v 1.3 2012/10/07 17:17:25 asau Exp $
#

DISTNAME=		TclCurl-7.19.6
PKGNAME=		tcl-curl-7.19.6
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://personal1.iddeo.es/andresgarci/tclcurl/download/tarball/

MAINTAINER=		bharder@methodlogic.net
HOMEPAGE=		http://personal1.iddeo.es/andresgarci/tclcurl/english/
COMMENT=		Curl bindings for Tcl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${PREFIX}/lib/tcl8.5

.include "../../wip/tcl85/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
