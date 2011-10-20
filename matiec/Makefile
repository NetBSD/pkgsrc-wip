# $NetBSD: Makefile,v 1.1.1.1 2011/10/20 21:38:56 manuosx Exp $
#

DISTNAME=tip
CATEGORIES=	devel
MASTER_SITES=	http://dev.automforge.net/matiec/archive/
EXTRACT_SUFX=	.zip

MAINTAINER= conti.ma@alice.it
HOMEPAGE=	http://dev.automforge.net/matiec/archive/
COMMENT= 	IEC61131-3 Compiler
LICENSE=	gnu-gpl-v3
PKG_DESTDIR_SUPPORT=	user-destdir
DEPENDS+=	bison>=2.4.3:../../devel/bison
WRKSRC=		${WRKDIR}/matiec-0b81b59f333b
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
