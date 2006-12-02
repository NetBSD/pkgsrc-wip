# $NetBSD: Makefile,v 1.2 2006/12/02 17:22:04 dhowland Exp $
#

DISTNAME=		xar-1.4
CATEGORIES=		archivers
MASTER_SITES=		http://www.opendarwin.org/projects/xar/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.opendarwin.org/projects/xar/
COMMENT=		The eXtensible ARchiver

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
