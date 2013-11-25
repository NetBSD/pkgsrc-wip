# $NetBSD: Makefile,v 1.4 2013/11/25 19:14:23 zul_ Exp $
#

DISTNAME=	girara-0.1.9
CATEGORIES=	x11
MASTER_SITES=	http://pwmt.org/projects/girara/download/

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura/
COMMENT=	Library to develop simple and minimalist user interface
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
