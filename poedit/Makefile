# $NetBSD: Makefile,v 1.1.1.1 2003/04/04 20:37:04 xtraeme Exp $
#

DISTNAME=	poedit-1.2.1	
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://poedit.sourceforge.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11BASE=		YES

.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
