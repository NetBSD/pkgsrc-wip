# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:14 asau Exp $
#

VERSION=3.0.1
DISTNAME=		sleuthkit-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sleuthkit/}

MAINTAINER=		oivulf@gmail.com
HOMEPAGE=		http://www.sleuthkit.org/
COMMENT=		OpenSource Forensic Toolkit

PKG_DESTDIR_SUPPORT=	none

USE_LANGUAGES=		c c++
USE_LIBTOOL= yes
USE_TOOLS+=		gmake file perl:run
GNU_CONFIGURE= YES

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
