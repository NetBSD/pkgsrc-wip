# $NetBSD: Makefile,v 1.1 2012/11/12 14:03:38 thomasklausner Exp $

DISTNAME=	tigervnc-1.2.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tigervnc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/apps/mediawiki/tigervnc/index.php?title=Main_Page
COMMENT=	High-performance, platform-neutral VNC client/server
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgmerge perl

REPLACE_PERL+=	unix/vncserver

.include "../../mk/jpeg.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
# pkgsrc version too new: error: 'gnutls_transport_set_global_errno' was not declared in this scope
#.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
# fltk and fltk13 are recognized, but cause compilation errors
# fltk2 is not recognized
.include "../../mk/bsd.pkg.mk"
