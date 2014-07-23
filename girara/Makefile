# $NetBSD: Makefile,v 1.6 2014/07/23 11:50:50 leot1990 Exp $
#

DISTNAME=	girara-0.2.2
CATEGORIES=	x11
MASTER_SITES=	http://pwmt.org/projects/girara/download/

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/girara/
COMMENT=	Library to develop simple and minimalist user interface
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
