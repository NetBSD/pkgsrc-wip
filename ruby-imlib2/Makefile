# $NetBSD: Makefile,v 1.1.1.1 2005/03/14 14:34:38 obache Exp $

DISTNAME=	imlib2-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-imlib2-${VER}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.pablotron.org/download/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.pablotron.org/software/imlib2-ruby/
COMMENT=	Imlib2 bindings for Ruby

USE_BUILDLINK3=	yes
USE_X11= yes

VER=		0.5.0
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-configure
SUBST_MESSAGE.libs=	If the X11 and Xext libraries are not weeded out,\
			they will be unresolved in the resulting .so
SUBST_FILES.libs=	extconf.rb
SUBST_SED.libs=		-e "s%\#{imlib2_config} --libs%\#{imlib2_config} --libs | ${SED} -e 's/-lX11//g' -e 's/-lXext//g'%"

REPLACE_RUBY_DIRS=	${WRKSRC}/examples

DOCS=		AUTHORS COPYING ChangeLog README TODO

PLIST_SRC=	${WRKDIR}/PLIST

post-install:
	cd ${WRKSRC}/examples && ${PAX} -rw -pp -pm . ${RUBY_EXAMPLESDIR}/imlib2
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/imlib2
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/imlib2
.endfor
	cd ${WRKSRC}/doc && ${PAX} -rw -pp -pm . ${RUBY_DOCDIR}/imlib2/api
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	cd ${RUBY_DOCDIR} && \
	${FIND} imlib2 \! -type d -print | ${SORT} | \
	while read FN; do \
	  ${ECHO} "\$${RUBY_DOCDIR}/$${FN}"; \
	done >> ${PLIST_SRC} && \
	${FIND} -d imlib2 -type d -print | \
	while read DIR; do \
	  ${ECHO} "@dirrm \$${RUBY_DOCDIR}/$${DIR}"; \
	done >> ${PLIST_SRC}

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
