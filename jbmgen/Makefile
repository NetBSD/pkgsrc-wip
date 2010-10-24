# $NetBSD: Makefile,v 1.6 2010/10/24 21:55:44 shattered Exp $
#

DISTNAME=		jbmgen-1.1.0
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		audio ruby
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jbmgen/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jbmgen.sourceforge.net/
COMMENT=		Archos Gmini playlist generator

NO_BUILD=		yes
REPLACE_RUBY=		jbmgen
JBMGEN_FILES=		BinaryStuff.rb Dictionary.rb FileEntry.rb JBMFile.rb \
			Path.rb Pointable.rb TreeNode.rb TreeNodeTypes.rb \
			mp3info.rb

post-extract:
	set -e; \
	for m in ${JBMGEN_FILES}; do \
		sed -e 's,require *[^ ]\([^\.]*\)\.rb.,require "jbmgen/\1",' \
			"${WRKSRC}/$$m" > "${WRKSRC}/$$m.new"; \
	done

do-install:
	mkdir ${RUBY_SITELIBDIR}/jbmgen
	set -e; \
	for m in ${JBMGEN_FILES}; do \
		${INSTALL_DATA} "${WRKSRC}/$$m.new" "${RUBY_SITELIBDIR}/jbmgen/$$m"; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/jbmgen ${PREFIX}/bin

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
