# $NetBSD: Makefile,v 1.3 2008/01/18 04:30:18 tnn2 Exp $
#

DISTNAME=		xar-1.4
PKGREVISION=		1
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
