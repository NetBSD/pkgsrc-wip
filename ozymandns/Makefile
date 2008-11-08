# $NetBSD: Makefile,v 1.1.1.1 2008/11/08 15:18:50 gschwarz Exp $

DISTNAME=	ozymandns_src_0.1
PKGNAME=	${DISTNAME:S/_src_/-/}
CATEGORIES=	net
MASTER_SITES=	http://www.doxpara.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://localhost.lu/localhostwiki/OzymanDNS/
COMMENT=	Tool to enable ssh tunnel over DNS using TXT records

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

DEPENDS+=		p5-Net-DNS:../../net/p5-Net-DNS
DEPENDS+=		p5-LWP-UserAgent-Determined:../../www/p5-LWP-UserAgent-Determined
DEPENDS+=		p5-MIME-Base32:../../converters/p5-MIME-Base32
DEPENDS+=		p5-MIME-Base64:../../converters/p5-MIME-Base64

do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} glance.c -o glance ${LDFLAGS}

do-install:
		cd ${WRKSRC} && ${INSTALL_PROGRAM} glance ${PREFIX}/sbin && ${INSTALL_SCRIPT} ${OZYMAN_PERLSCRIPTS} ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
