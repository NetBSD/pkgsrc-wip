# $NetBSD: Makefile,v 1.6 2005/04/11 21:09:37 tvierling Exp $

DISTNAME=		WEPCrack-0.0.10
WRKSRC=			${WRKDIR}
CATEGORIES=		security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wepcrack/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://wepcrack.sourceforge.net/
COMMENT=		Open source tool for breaking 802.11 WEP secret keys

USE_PERL5=		YES
REPLACE_PERL=	${WRKSRC}/*.pl

do-install:
	for A in ${WRKSRC}/*.pl; do \
	${INSTALL_SCRIPT} $$A ${PREFIX}/bin/; \
	done

.include	"../../mk/bsd.pkg.mk"
