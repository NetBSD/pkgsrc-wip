# $NetBSD: Makefile,v 1.1.1.1 2004/03/30 22:13:11 poppnk Exp $
#

DISTNAME=		xmlindent-0.2.16
CATEGORIES=		wip
MASTER_SITES=		http://www.cs.helsinki.fi/u/penberg/xmlindent/src/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cs.helsinki.fi/u/penberg/xmlindent/src/
COMMENT=		XML stream reformatter written in ANSI C

# XXX *BSD have -lfl in the base...solaris,irix,linux ? propbably they need that
#DEPENDS=		flex>2.5:../../devel/flex 

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlindent ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/xmlindent.1 ${PREFIX}/share/man/man1/

.include "../../mk/bsd.pkg.mk"
