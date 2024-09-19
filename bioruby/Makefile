# $NetBSD: Makefile,v 1.7 2012/09/30 09:51:35 noud4 Exp $
#

DISTNAME=		bioruby-0.6.2
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		biology ruby
MASTER_SITES=		http://raa.ruby-lang.org/cache/bioruby/ \
			http://bioruby.org/archive/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://bioruby.org/
COMMENT=		Intergrated environment for Bioinformatics using Ruby
LICENSE=		gnu-gpl-v2

USE_RUBY=		yes
USE_RUBY_EXTCONF=	yes
REPLACE_RUBY_DIRS=	${WRKSRC}/bin ${WRKSRC}/sample
REPLACE_FILE_PAT=	*

RUBY_EXAMPLESDIR=	${PREFIX}/share/examples
INSTALLATION_DIRS=	bin ${RUBY_DOCDIR}/bioruby/ja ${RUBY_EXAMPLESDIR:S|${PREFIX}/||}/bioruby
PLIST_SUBST+=		RUBY_EXAMPLESDIR=${RUBY_EXAMPLESDIR:S|${PREFIX}/||}

SCRIPTS=		br_biofetch.rb br_bioflat.rb br_biogetseq.rb \
			br_pmfetch.rb
DOC=			COPYING COPYING.LIB ChangeLog README
DOC_ja=			BioRuby.rd.ja Design.rd.ja KEGG_API.rd.ja \
			TODO.rd.ja Tutorial.rd.ja

post-install:
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} \
		${DESTDIR}${PREFIX}/bin/`${BASENAME} ${f} .rb | ${SED} -e 's/^br_//'`
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${RUBY_DOC}/bioruby/ja
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/bioruby
.endfor
.for f in ${DOC_ja}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/bioruby/ja
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/bioruby
	cd ${WRKSRC}/sample && ${INSTALL_DATA} * ${DESTDIR}${RUBY_EXAMPLESDIR}/bioruby

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
