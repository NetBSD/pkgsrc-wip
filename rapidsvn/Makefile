# $NetBSD: Makefile,v 1.3 2003/08/28 09:48:47 xtraeme Exp $
#

DISTNAME=	rapidsvn-0.1.3
CATEGORIES=	devel
MASTER_SITES=	http://rapidsvn.tigris.org/files/documents/341/5143/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://rapidsvn.tigris.org/
COMMENT=	Cross-platform GUI front-end for the Subversion

DEPENDS+=               docbook-xsl>=1.61.2:../../textproc/docbook-xsl

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-svn-include=${PREFIX}/include
CONFIGURE_ARGS+=	--with-svn-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-xsltproc
CONFIGURE_ARGS+=	--with-docbook-xsl=${PREFIX}/share/xsl/docbook

.include "../../devel/subversion/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
