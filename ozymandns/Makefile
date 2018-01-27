# $NetBSD: Makefile,v 1.7 2013/12/19 12:14:16 gschwarz Exp $

DISTNAME=	ozymandns_src_0.1
PKGNAME=	${DISTNAME:S/_src_/-/}
CATEGORIES=	net
MASTER_SITES=	http://www.cship.info/mirror/dnstunnel/ http://beta.ivancover.com/dnstunnel/ http://wiki.kartbuilding.net/ http://s3.amazonaws.com/dmk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://dankaminsky.com/2004/07/29/51/
COMMENT=	Tool to enable ssh tunnel over DNS using TXT records

DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=		p5-LWP-UserAgent-Determined-[0-9]*:../../www/p5-LWP-UserAgent-Determined
DEPENDS+=		p5-MIME-Base32-[0-9]*:../../converters/p5-MIME-Base32
DEPENDS+=		p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		YES
OZYMAN_PERLSCRIPTS=	aska.pl droute.pl geta.pl nomde.pl

USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	sbin

SUBST_CLASSES+=		perlfix
SUBST_STAGE.perlfix=	post-patch
SUBST_MESSAGE.perlfix=	Fixing perl path
SUBST_FILES.perlfix=	${OZYMAN_PERLSCRIPTS}
SUBST_SED.perlfix=	-e 's:^\#!/usr/bin/perl:\#!${PERL5}:g'

LIBS.SunOS+=	-lnsl # for gethostbyname

do-build:
		cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} glance.c -o glance ${LDFLAGS} ${LIBS}

do-install:
		cd ${WRKSRC} && ${INSTALL_PROGRAM} glance ${DESTDIR}${PREFIX}/sbin && ${INSTALL_SCRIPT} ${OZYMAN_PERLSCRIPTS} ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
