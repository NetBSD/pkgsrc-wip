# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 18:05:21 daprice Exp $
#

DISTNAME=		T-COFFEE_distribution
PKGNAME=		t-coffee-1.37
WRKSRC=		 	${WRKDIR}/T-COFFEE_distribution_Version_1.37/t_coffee_source
CATEGORIES=		biology
MASTER_SITES=		http://igs-server.cnrs-mrs.fr/~cnotred/Packages/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://igs-server.cnrs-mrs.fr/~cnotred/Packages/
COMMENT=		Multiple Sequence Alignment Package

DEPENDS+=               clustalw-1.8:../../biology/clustalw

MESSAGE_SUBST+=         PREFIX=${PREFIX}
MAKEFILE=               makefile
USE_BUILDLINK3=         yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/tcoffee
.for HTML in t_coffee.html t_coffee4html.cgi t_coffee_doc.html
	${INSTALL_DATA} ${WRKSRC}/../html/${HTML} ${PREFIX}/share/doc/html/tcoffee
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/t_coffee ${PREFIX}/bin

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcoffee
.for DOC in README4T-COFFEE t_coffee_doc.doc t_coffee_doc.pdf \
		t_coffee.pdf t_coffee_doc.html t_coffee_doc.ps
	${INSTALL_DATA} ${WRKSRC}/../doc/${DOC} ${PREFIX}/share/doc/tcoffee
.endfor

.include "../../mk/bsd.pkg.mk"

