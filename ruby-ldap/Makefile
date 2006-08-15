# $NetBSD: Makefile,v 1.1.1.1 2006/08/15 17:05:25 obache Exp $

DISTNAME=	ruby-ldap-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-ldap-${VER}
CATEGORIES=	databases ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-ldap/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://ruby-ldap.sourceforge.net/
COMMENT=	LDAP extension module for Ruby

VER=		0.9.7

REPLACE_RUBY_DIRS=	${WRKSRC}/example ${WRKSRC}/example/cgi
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes

.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openldap2
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
