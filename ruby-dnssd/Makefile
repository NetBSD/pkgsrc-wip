# $NetBSD: Makefile,v 1.7 2011/03/04 04:40:35 obache Exp $
#

DISTNAME=	dnssd-2.0
CATEGORIES=	net ruby

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/dnssd
COMMENT=	DNS Service Discovery (aka Bonjour, MDNS) API for Ruby
LICENSE=	ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_CLEANBUILD=	ext/dnssd/*.o ext/dnssd/mkmf.log ext/dnssd/Makefile

.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
