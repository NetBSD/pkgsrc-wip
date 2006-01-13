# $NetBSD: Makefile,v 1.8 2006/01/13 01:45:31 rillig Exp $

DISTNAME=		WEPCrack-0.1.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wepcrack/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wepcrack.sourceforge.net/
COMMENT=		Open source tool for breaking 802.11 WEP secret keys

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
USE_TOOLS+=		perl:run

REPLACE_PERL+=		*.pl

do-install:
	set -e;								\
	cd ${WRKSRC:Q} && for f in *.pl; do				\
		${INSTALL_SCRIPT} "./$$f" ${PREFIX:Q}/bin/;		\
	done

.include "../../mk/bsd.pkg.mk"
