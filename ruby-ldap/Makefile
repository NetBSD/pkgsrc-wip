# $NetBSD: Makefile,v 1.2 2006/08/16 04:43:06 obache Exp $

DISTNAME=	ruby-ldap-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ldap-${VER}
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-ldap/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://ruby-ldap.sourceforge.net/
COMMENT=	LDAP extension module for Ruby

VER=		0.9.7

REPLACE_RUBY_DIRS=	example/pr_ctl example/cgi/search.cgi
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes

.include "options.mk"

DOCS=		ChangeLog FAQ README TODO

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/ldap
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/ldap
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ldap
	cd ${WRKSRC}/example && ${PAX} -rw -pp * ${RUBY_EXAMPLESDIR}/ldap

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
