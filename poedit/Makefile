# $NetBSD: Makefile,v 1.2 2003/04/17 13:17:24 xtraeme Exp $
#

DISTNAME=	poedit-1.2.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://poedit.sourceforge.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor

DEPENDS+=		zip-[0-9]*:../../archivers/zip

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES

.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
