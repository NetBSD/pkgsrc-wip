# $NetBSD: Makefile,v 1.8 2009/05/19 09:00:12 thomasklausner Exp $

DISTNAME=	ruby-ldap-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ldap-${VER}
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-ldap/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://ruby-ldap.sourceforge.net/
COMMENT=	LDAP extension module for Ruby
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

VER=		0.9.8

REPLACE_RUBY_DIRS=	example/pr_ctl example/cgi/search.cgi
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
USE_TOOLS+=		pax

.include "options.mk"

DOCS=		ChangeLog FAQ README TODO

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR}/ldap
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${RUBY_DOCDIR}/ldap
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_EXAMPLESDIR}/ldap
	cd ${WRKSRC}/example && pax -rw -pp * ${DESTDIR}${RUBY_EXAMPLESDIR}/ldap

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
