# $NetBSD: Makefile,v 1.7 2012/11/13 19:33:45 othyro Exp $
#

DISTNAME=		xar-1.5.2
PKGREVISION=		1
CATEGORIES=		archivers
MASTER_SITES=		http://xar.googlecode.com/files/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://code.google.com/p/xar/
COMMENT=		The eXtensible ARchiver


GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
