# $NetBSD: Makefile,v 1.1.1.1 2005/06/09 13:08:24 obache Exp $
#

DISTNAME=	gallery-0.0.8
PKGNAME=	${RUBY_PKGPREFIX}-GalleryAdministrator-0.0.8
CATEGORIES=	graphics ruby www
MASTER_SITES=	http://www.cozmixng.org/~kou/download/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.cozmixng.org/~rwiki/?cmd=view;name=GalleryAdministrator
COMMENT=	CGI and mail interface for [RAA:RubyPhoto] and zphoto

RUBY_VERSION_SUPPORTED= 18

DEPENDS+=	{${RUBY_PKGPREFIX}-imlib2>=0.4.3,${RUBY_PKGPREFIX}-RMagick>=1.8.1}:../../graphics/ruby-imlib2
DEPENDS+=	{${RUBY_PKGPREFIX}-uconv-[0-9]*,${RUBY_PKGPREFIX}-iconv-[0-9]*}:../../converters/ruby-uconv

USE_RUBY=	yes
NO_BUILD=	yes
USE_RUBY_SETUP=	yes
REPLACE_RUBY=	bin/rubyphoto.rb interface/admin.rb interface/mail_admin.rb \
		sample/counter.rb sample/initgallery.rb \
		test/run-test.rb test/test-base.rb

DOCS=		COPYING_for_RubyPhoto README.en README.ja README_for_RubyPhoto.html

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/gallery
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/gallery
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gallery
	cd ${WRKSRC}/sample && ${PAX} -rw -pp * ${RUBY_EXAMPLESDIR}/gallery
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gallery/interface
	${INSTALL_SCRIPT} ${WRKSRC}/interface/admin.rb ${RUBY_EXAMPLESDIR}/gallery/interface
	${INSTALL_SCRIPT} ${WRKSRC}/interface/mail_admin.rb ${RUBY_EXAMPLESDIR}/gallery/interface

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
