# $NetBSD: Makefile,v 1.10 2010/02/03 12:12:51 pettai Exp $

DISTNAME=	dnsruby-1.43
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://dnsruby.rubyforge.org/
COMMENT=	Ruby DNS client library

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_BUILD=      gemspec

post-extract:
	${MKDIR} -p ${WRKSRC}/html/classes
	${MKDIR} -p ${WRKSRC}/html/files

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
