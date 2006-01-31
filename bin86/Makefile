# $NetBSD: Makefile,v 1.8 2006/01/31 02:43:34 rillig Exp $

DISTNAME=		bin86-0.16.17
CATEGORIES=		devel
MASTER_SITES=		http://homepage.ntlworld.com/robert.debath/dev86/

MAINTAINER=		reed@reedmedia.net
COMMENT=		Simple assembler and linker for x86 machine code

# devel/bcc also provides as86 and ld86
CONFLICTS=		bcc-*

USE_TOOLS+=		gmake

do-build:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX:Q}

do-install:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX:Q} install

.include "../../mk/bsd.pkg.mk"
