# $NetBSD: Makefile,v 1.6 2012/10/07 20:11:08 asau Exp $
#

DISTNAME=		xar-1.5.2
PKGREVISION=		1
CATEGORIES=		archivers
MASTER_SITES=		http://xar.googlecode.com/files/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://code.google.com/p/xar/
COMMENT=		The eXtensible ARchiver

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
