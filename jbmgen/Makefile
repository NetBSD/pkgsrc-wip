# $NetBSD: Makefile,v 1.1.1.1 2005/12/10 22:09:57 shattered Exp $
#

DISTNAME=		jbmgen-1.1.0
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		audio ruby
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jbmgen/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://jbmgen.sourceforge.net/
COMMENT=		Archos Gmini playlist generator

NO_BUILD=	yes
USE_RUBY=	yes
REPLACE_RUBY_DIRS=	${WRKSRC}/.
REPLACE_FILE_PAT=	jbmgen

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/jbmgen
	for m in BinaryStuff.rb Dictionary.rb FileEntry.rb JBMFile.rb \
		Path.rb Pointable.rb TreeNode.rb TreeNodeTypes.rb \
		mp3info.rb; do \
		${SED} -e 's,require *[^ ]\([^\.]*\)\.rb.,require "jbmgen/\1",' \
			${WRKSRC}/$$m > ${WRKSRC}/$$m.new; \
		${INSTALL_DATA} ${WRKSRC}/$$m.new ${RUBY_SITELIBDIR}/jbmgen/$$m; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/jbmgen ${PREFIX}/bin

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
