# $NetBSD: Makefile,v 1.5 2003/08/15 12:01:06 marc Exp $
#

DISTNAME=		scons-0.91
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.scons.org/
COMMENT=		Build system, written in Python

PYDISTUTILSPKG=		yes
USE_BUILDLINK2=		yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/scons.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sconsign.1 ${PREFIX}/man/man1

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
