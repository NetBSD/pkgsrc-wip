# $NetBSD: Makefile,v 1.2 2003/12/05 00:56:55 mpasternak Exp $
#

DISTNAME=		xbase-2.0.0
CATEGORIES=		wip
MASTER_SITES=		http://www.rekallrevealed.org/packages/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.rekallrevealed.org/packages/
COMMENT=		Xbase (i.e. dBase, FoxPro, etc.) compatible C++ class library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
