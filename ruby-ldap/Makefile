# $NetBSD: Makefile,v 1.5 2008/05/26 13:59:46 tnn2 Exp $

DISTNAME=	ruby-ldap-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ldap-${VER}
PKGREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-ldap/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://ruby-ldap.sourceforge.net/
COMMENT=	LDAP extension module for Ruby

VER=		0.9.7

REPLACE_RUBY_DIRS=	example/pr_ctl example/cgi/search.cgi
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
USE_TOOLS+=		pax

.include "options.mk"

DOCS=		ChangeLog FAQ README TODO

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/ldap
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/ldap
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/ldap
	cd ${WRKSRC}/example && pax -rw -pp * ${RUBY_EXAMPLESDIR}/ldap

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
