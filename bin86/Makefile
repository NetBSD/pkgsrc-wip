# $NetBSD: Makefile,v 1.11 2008/03/07 23:57:58 jeremy-c-reed Exp $

DISTNAME=		bin86-0.16.17
CATEGORIES=		devel
MASTER_SITES=		http://homepage.ntlworld.com/robert.debath/dev86/ \
			http://www.debath.co.uk/dev86/bin86-0.16.17.tar.gz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.debath.co.uk/
COMMENT=		Simple assembler and linker for x86 machine code

# devel/bcc also provides as86 and ld86
CONFLICTS=		bcc-[0-9]*

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX:Q}

do-install:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX:Q} PKGMANDIR=${PKGMANDIR:Q} install

.include "../../mk/bsd.pkg.mk"
