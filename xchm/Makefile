# $NetBSD: Makefile,v 1.1.1.1 2003/09/05 02:35:36 xtraeme Exp $
#

DISTNAME=	xchm-0.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xchm.sourceforge.net/
COMMENT=	CHM viewer for UNIX

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../wip/chmlib/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
