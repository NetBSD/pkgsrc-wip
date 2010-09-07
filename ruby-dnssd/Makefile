# $NetBSD: Makefile,v 1.5 2010/09/07 11:48:03 obache Exp $
#

DISTNAME=	dnssd-1.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net ruby

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/dnssd
COMMENT=	DNS Service Discovery (aka Bonjour, MDNS) API for Ruby
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_BUILD=	gemspec
GEM_CLEANBUILD=	ext/dnssd/*.o ext/dnssd/mkmf.log ext/dnssd/Makefile

.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
