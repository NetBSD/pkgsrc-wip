# $NetBSD: Makefile,v 1.2 2006/05/19 16:51:18 ykomatsu Exp $

DISTNAME=	gtklp-1.2.1
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtklp/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtklp.sourceforge.net/
COMMENT=	GUI for CUPS print submission and queue management

BUILD_DEPENDS+= gettext>=0.11.5:../../devel/gettext

USE_TOOLS+=	gmake
USE_TOOLS+=	autoconf
USE_TOOLS+=	automake
USE_TOOLS+=	pkg-config
USE_PKGLOCALEDIR=YES
GNU_CONFIGURE=	yes

DOCDIR=		${PREFIX}/share/doc/gtklp

.include "../../print/cups/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README USAGE ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
