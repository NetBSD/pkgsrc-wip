# $NetBSD: Makefile,v 1.1.1.1 2003/07/16 23:15:34 xtraeme Exp $
#

DISTNAME=	rapidsvn-0.1.3
CATEGORIES=	devel
MASTER_SITES=	http://rapidsvn.tigris.org/files/documents/341/5143/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://rapidsvn.tigris.org/
COMMENT=	Cross-platform GUI front-end for the Subversion

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-svn-include=${PREFIX}/include
CONFIGURE_ARGS+=	--with-svn-lib=${PREFIX}/lib

.include "../../devel/subversion/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
