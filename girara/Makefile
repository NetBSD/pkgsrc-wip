# $NetBSD: Makefile,v 1.3 2013/06/26 18:27:54 zul_ Exp $
#

DISTNAME=	girara-0.1.6
CATEGORIES=	x11
MASTER_SITES=	http://pwmt.org/projects/girara/download/

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	http://pwmt.org/projects/zathura/
COMMENT=	Library to develop simple and minimalist user interface
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config gettext gmake groff
USE_LIBTOOL=	yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
