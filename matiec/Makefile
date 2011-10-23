# $NetBSD: Makefile,v 1.3 2011/10/23 10:06:50 thomasklausner Exp $
#

DISTNAME=	matiec-0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.beremiz.org/documentation/the-iec-to-c-compiler

MAINTAINER=	conti.ma@alice.it
HOMEPAGE=	http://www.beremiz.org/documentation/the-iec-to-c-compiler
COMMENT= 	IEC61131-3 Compiler
LICENSE=	gnu-gpl-v3
PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=	bison
WRKSRC=		${WRKDIR}/matiec
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

HG_REPOSITORIES=	matiec
HG_REPO.matiec=	http://dev.automforge.net/matiec

.include "../mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
