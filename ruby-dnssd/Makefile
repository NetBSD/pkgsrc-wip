# $NetBSD: Makefile,v 1.8 2012/10/07 14:53:44 asau Exp $
#

DISTNAME=	dnssd-2.0
CATEGORIES=	net ruby

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/dnssd
COMMENT=	DNS Service Discovery (aka Bonjour, MDNS) API for Ruby
LICENSE=	ruby-license

GEM_CLEANBUILD=	ext/dnssd/*.o ext/dnssd/mkmf.log ext/dnssd/Makefile

.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
