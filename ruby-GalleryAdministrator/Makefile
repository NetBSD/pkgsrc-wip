# $NetBSD: Makefile,v 1.11 2010/09/14 07:33:46 obache Exp $
#

DISTNAME=	gallery-0.0.8
PKGREVISION=	1
CATEGORIES=	graphics ruby www
MASTER_SITES=	http://www.cozmixng.org/~kou/download/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.cozmixng.org/~rwiki/?cmd=view;name=GalleryAdministrator
COMMENT=	CGI and mail interface for [RAA:RubyPhoto] and zphoto

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{${RUBY_PKGPREFIX}-imlib2>=0.4.3,${RUBY_PKGPREFIX}-RMagick>=1.8.1}:../../graphics/ruby-imlib2
DEPENDS+=	{${RUBY_PKGPREFIX}-uconv-[0-9]*,${RUBY_PKGPREFIX}-iconv-[0-9]*}:../../converters/ruby-uconv

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
CONFIGURE_ARGS+=--site-ruby=${PREFIX}/${RUBY_VENDORLIB}
REPLACE_RUBY=	bin/rubyphoto.rb interface/admin.rb interface/mail_admin.rb \
		sample/counter.rb sample/initgallery.rb \
		test/run-test.rb test/test-base.rb

DOCS=		COPYING_for_RubyPhoto README.en README.ja README_for_RubyPhoto.html

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR:Q}/gallery
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${DESTDIR}${RUBY_DOCDIR:Q}/gallery
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR:Q}/gallery
	cd ${WRKSRC:Q}/sample && pax -rw -pp * ${DESTDIR}${RUBY_EXAMPLESDIR:Q}/gallery
	${RM} -r ${DESTDIR}${RUBY_EXAMPLESDIR:Q}/gallery/templates/.en/.svn
	${RM} -r ${DESTDIR}${RUBY_EXAMPLESDIR:Q}/gallery/templates/.ja/.svn
	${RM} -r ${DESTDIR}${RUBY_EXAMPLESDIR:Q}/gallery/templates/.ja.i/.svn
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR:Q}/gallery/interface
	${INSTALL_SCRIPT} ${WRKSRC:Q}/interface/admin.rb ${DESTDIR}${RUBY_EXAMPLESDIR:Q}/gallery/interface
	${INSTALL_SCRIPT} ${WRKSRC:Q}/interface/mail_admin.rb ${DESTDIR}${RUBY_EXAMPLESDIR:Q}/gallery/interface

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
