# $NetBSD: Makefile,v 1.2 2003/05/25 23:55:53 marc Exp $
#

DISTNAME=		scons-0.14
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.scons.org/
COMMENT=		build system, written in Python

PYDISTUTILSPKG=		yes
USE_BUILDLINK2=		yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/scons.1 ${PREFIX}/man/man1

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
