# $NetBSD: Makefile,v 1.2 2005/04/11 21:10:10 tvierling Exp $
#

DISTNAME=		bioruby-0.4.0
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.bioruby.org/bioruby/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://bioruby.org
COMMENT=		Intergrated environment for Bioinformatics using Ruby

NO_BUILD=		yes

do-configure:
	cd ${WRKSRC}; \
	${RUBY} install.rb config; \
	${RUBY} install.rb setup;

do-install:
	cd ${WRKSRC}; \
	${RUBY} install.rb install

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bioruby
.for DOC in *
	${INSTALL_DATA} ${WRKSRC}/doc/${DOC} ${PREFIX}/share/doc/bioruby
.endfor
.for DOC in README COPYING COPYING.LIB
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/bioruby
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bioruby
.for EXA in *
	${INSTALL_DATA} ${WRKSRC}/sample/${EXA} \
		${PREFIX}/share/examples/bioruby
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

