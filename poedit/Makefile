# $NetBSD: Makefile,v 1.3 2003/04/19 18:12:01 lsed Exp $
#

DISTNAME=	poedit-1.2.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://poedit.sourceforge.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor

DEPENDS+=		zip-[0-9]*:../../archivers/zip

BUILDLINK_DEPENDS.db3=	db3>=3.1

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11=		YES

.include "../../databases/db3/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
