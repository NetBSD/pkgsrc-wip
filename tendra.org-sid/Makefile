# $NetBSD: Makefile,v 1.4 2012/10/07 17:17:30 asau Exp $
#

DISTNAME=	sid-1.10
CATEGORIES=	devel
MASTER_SITES=	http://www.tendra.org/releases/sid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tendra.org/wiki/SID
COMMENT=	SID (Syntax Improving Device) is an LL(1) parser generator

BUILD_DEPENDS+=		libxslt>=1.1.0:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xml>=4.2nb4:../../textproc/docbook-xml
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl


USE_TOOLS+=	perl

.include "../../mk/bsd.pkg.mk"
