# $NetBSD: Makefile,v 1.9 2015/04/14 18:14:30 leot1990 Exp $
#

DISTNAME=	girara-0.2.4
CATEGORIES=	x11
MASTER_SITES=	http://pwmt.org/projects/girara/download/

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/girara/
COMMENT=	Library to develop simple and minimalist user interface
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes

MAKE_ENV+=	COLOR=0

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
