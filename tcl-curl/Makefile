# $NetBSD: Makefile,v 1.2 2010/01/17 12:03:33 thomasklausner Exp $
#

DISTNAME=		TclCurl-7.19.6
PKGNAME=		tcl-curl-7.19.6
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://personal1.iddeo.es/andresgarci/tclcurl/download/tarball/

MAINTAINER=		bharder@methodlogic.net
HOMEPAGE=		http://personal1.iddeo.es/andresgarci/tclcurl/english/
COMMENT=		Curl bindings for Tcl

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${PREFIX}/lib/tcl8.5

.include "../../wip/tcl85/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
