# $NetBSD: Makefile,v 1.1.1.1 2005/02/25 20:18:24 daprice Exp $
#

DISTNAME=		bioruby-0.4.0
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.bioruby.org/bioruby/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://bioruby.org
COMMENT=		Intergrated environment for Bioinformatics using Ruby

NO_BUILD=		yes
USE_BUILDLINK3=		yes

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

