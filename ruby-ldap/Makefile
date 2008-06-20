# $NetBSD: Makefile,v 1.6 2008/06/20 05:20:17 obache Exp $

DISTNAME=	ruby-ldap-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ldap-${VER}
PKGREVISION=	2
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-ldap/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://ruby-ldap.sourceforge.net/
COMMENT=	LDAP extension module for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

VER=		0.9.7

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
