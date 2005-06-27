# $NetBSD: Makefile,v 1.3 2005/06/27 13:56:14 thomasklausner Exp $
#

DISTNAME=		bioruby-0.6.2
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		biology ruby
MASTER_SITES=		http://raa.ruby-lang.org/cache/bioruby/ \
			http://bioruby.org/archive/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://bioruby.org/
COMMENT=		Intergrated environment for Bioinformatics using Ruby

USE_RUBY=		yes
USE_RUBY_EXTCONF=	yes
REPLACE_RUBY_DIRS=	${WRKSRC}/bin ${WRKSRC}/sample
REPLACE_FILE_PAT=	*

SCRIPTS=		br_biofetch.rb br_bioflat.rb br_biogetseq.rb \
			br_pmfetch.rb
DOC=			COPYING COPYING.LIB ChangeLog README
DOC_ja=			BioRuby.rd.ja Design.rd.ja KEGG_API.rd.ja \
			TODO.rd.ja Tutorial.rd.ja

post-install:
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} \
		${PREFIX}/bin/`${BASENAME} ${f} .rb | ${SED} -e 's/^br_//'`
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/bioruby/ja
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/bioruby
.endfor
.for f in ${DOC_ja}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${RUBY_DOCDIR}/bioruby/ja
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/bioruby
	cd ${WRKSRC}/sample && ${CP} * ${RUBY_EXAMPLESDIR}/bioruby

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"

