# $NetBSD: Makefile,v 1.7 2006/01/17 09:13:36 rillig Exp $

DISTNAME=		bin86-0.16.11
CATEGORIES=		devel
MASTER_SITES=		http://www.cix.co.uk/~mayday/dev86/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
COMMENT=	 	Simple assember and linker for x86 machine code

# devel/bcc also provides as86 and ld86
CONFLICTS=		bcc-*

# XXX as it this is now, it won't build under NetBSD
# XXX maybe patches under devel/bcc will help
ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86

USE_TOOLS+=		gmake

do-build:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX:Q}

do-install:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX:Q} install

.include "../../mk/bsd.pkg.mk"
