# $NetBSD: Makefile,v 1.4 2008/02/02 00:46:03 dhowland Exp $
#

DISTNAME=		xar-1.5.2
CATEGORIES=		archivers
MASTER_SITES=		http://xar.googlecode.com/files/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://code.google.com/p/xar/
COMMENT=		The eXtensible ARchiver

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
