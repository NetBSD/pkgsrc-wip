# $NetBSD: Makefile,v 1.8 2013/01/27 17:09:10 othyro Exp $
#

DISTNAME=	jbmgen-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jbmgen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jbmgen.sourceforge.net/
COMMENT=	Archos Gmini playlist generator
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
REPLACE_RUBY=	jbmgen
JBMGEN_FILES=	BinaryStuff.rb Dictionary.rb FileEntry.rb JBMFile.rb Path.rb
JBMGEN_FILES+=	Pointable.rb TreeNode.rb TreeNodeTypes.rb mp3info.rb

post-extract:
	set -e; \
	for m in ${JBMGEN_FILES}; do \
		sed -e 's,require *[^ ]\([^\.]*\)\.rb.,require "jbmgen/\1",' \
			"${WRKSRC}/$$m" > "${WRKSRC}/$$m.new"; \
	done

INSTALLATION_DIRS=	bin ${RUBY_SITELIB}/jbmgen

do-install:
	set -e; \
	for m in ${JBMGEN_FILES}; do \
		${INSTALL_DATA} "${WRKSRC}/$$m.new" ${DESTDIR}${PREFIX}/${RUBY_SITELIB}/jbmgen/"$$m"; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/jbmgen ${DESTDIR}${PREFIX}/bin

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
