# $NetBSD: Makefile,v 1.14 2013/06/12 16:51:13 noud4 Exp $
#

DISTNAME=		xbase-2.1.0
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xdb/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://linux.techass.com/projects/xdb/
COMMENT=		Xbase (i.e. dBase, FoxPro, etc.) compatible C++ class library

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CFLAGS+=		-DXBASE_DEBUG

.include "../../mk/bsd.pkg.mk"
