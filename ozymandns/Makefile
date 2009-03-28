# $NetBSD: Makefile,v 1.2 2009/03/28 16:59:55 thomasklausner Exp $

DISTNAME=	ozymandns_src_0.1
PKGNAME=	${DISTNAME:S/_src_/-/}
CATEGORIES=	net
MASTER_SITES=	http://www.doxpara.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://localhost.lu/localhostwiki/OzymanDNS/
COMMENT=	Tool to enable ssh tunnel over DNS using TXT records

DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=		p5-LWP-UserAgent-Determined-[0-9]*:../../www/p5-LWP-UserAgent-Determined
DEPENDS+=		p5-MIME-Base32-[0-9]*:../../converters/p5-MIME-Base32
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
OZYMAN_PERLSCRIPTS=	aska.pl droute.pl geta.pl nomde.pl

USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	sbin

SUBST_CLASSES+=         perlfix
SUBST_STAGE.perlfix=    post-patch
SUBST_MESSAGE.perlfix=  Fixing perl path
SUBST_FILES.perlfix=    ${OZYMAN_PERLSCRIPTS}
SUBST_SED.perlfix=      -e 's:^\#!/usr/bin/perl:\#!${PERL5}:g'

do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} glance.c -o glance ${LDFLAGS}

do-install:
		cd ${WRKSRC} && ${INSTALL_PROGRAM} glance ${PREFIX}/sbin && ${INSTALL_SCRIPT} ${OZYMAN_PERLSCRIPTS} ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
