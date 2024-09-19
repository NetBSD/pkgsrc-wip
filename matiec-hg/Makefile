# $NetBSD: Makefile,v 1.4 2012/10/03 15:09:52 asau Exp $
#

DISTNAME=	matiec-0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.beremiz.org/documentation/the-iec-to-c-compiler

MAINTAINER=	conti.ma@alice.it
HOMEPAGE=	https://bitbucket.org/mjsousa/matiec/
COMMENT=	IEC61131-3 Compiler
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bison
WRKSRC=		${WRKDIR}/matiec
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

HG_REPOSITORIES=	matiec
HG_REPO.matiec=		https://bitbucket.org/mjsousa/matiec

.include "../mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
