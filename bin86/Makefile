# $NetBSD: Makefile,v 1.2 2003/07/21 17:33:11 marttikuparinen Exp $

DISTNAME=		bin86-0.16.11
CATEGORIES=		devel
MASTER_SITES=		http://www.cix.co.uk/~mayday/dev86/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
COMMENT=	 	Simple assember and linker for x86 machine code

# devel/bcc also provides as86 and ld86
CONFLICTS=		bcc-*

# XXX as it this is now, it won't build under NetBSD
# XXX maybe patches under devel/bcc will help
ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86

USE_GMAKE=		YES

do-build:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX}

do-install:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX} install

.include "../../mk/bsd.pkg.mk"
