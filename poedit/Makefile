# $NetBSD: Makefile,v 1.4 2003/05/09 03:38:00 xtraeme Exp $
#

DISTNAME=	poedit-1.2.2
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

.if defined(POEDIT_USES_DB4) && ${POEDIT_USES_DB4} == YES
BUILDLINK_DEPENDS.db4=  db4>=4.0
.include "../../databases/db4/buildlink2.mk"
.endif

.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
