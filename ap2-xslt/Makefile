# $NetBSD: Makefile,v 1.4 2004/05/07 01:57:49 xtraeme Exp $
#

DISTNAME=	mod-xslt-1.0.0rc1
WRKSRC=         ${WRKDIR}/mod-xslt
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-xslt/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mod-xslt.com/mod-xslt/
COMMENT=	Apache2 module which transforms XML documents using XSL

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-exslt
CONFIGURE_ARGS+=	--with-apache-config=${PKG_SYSCONFDIR}/httpd
CONFIGURE_ARGS+=	--with-apache-documents=${PREFIX}/share/httpd/htdocs
CONFIGURE_ARGS+=	--with-apache-modules=${PREFIX}/lib/httpd
CONFIGURE_ARGS+=	--with-apache-include=${PREFIX}/include/httpd

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
