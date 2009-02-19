# $NetBSD: Makefile,v 1.1 2009/02/19 15:53:18 fulviociriaco Exp $
#

VERSION=3.0.1
DISTNAME=		sleuthkit-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sleuthkit/}

MAINTAINER=		oivulf@gmail.com
HOMEPAGE=		http://www.sleuthkit.org/
COMMENT=		OpenSource Forensic Toolkit

USE_LANGUAGES=		c c++
USE_LIBTOOL= yes
USE_TOOLS+=		gmake file perl:run
GNU_CONFIGURE= YES

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
