# $NetBSD: Makefile,v 1.8 2004/01/25 02:33:15 grantbeattie Exp $
#

DISTNAME=	poedit-1.2.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poedit/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://poedit.sourceforge.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor

DEPENDS+=	zip-[0-9]*:../../archivers/zip

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11=		YES

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS=	POEDIT_USES_DB4

POEDIT_USES_DB4?=	NO

.if defined(POEDIT_USES_DB4) && !empty(POEDIT_USES_DB4:M[Yy][Ee][Ss])
BUILDLINK_DEPENDS.db4=  db4>=4.0
.include "../../databases/db4/buildlink2.mk"
.endif

.include "../../x11/wxGTK/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
