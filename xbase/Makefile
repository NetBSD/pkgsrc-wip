# $NetBSD: Makefile,v 1.6 2004/08/17 18:33:02 tvierling Exp $
#

DISTNAME=		xbase-2.0.0
CATEGORIES=		databases
MASTER_SITES=		http://www.rekallrevealed.org/packages/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.rekallrevealed.org/packages/
COMMENT=		Xbase (i.e. dBase, FoxPro, etc.) compatible C++ class library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libxbase.la
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
