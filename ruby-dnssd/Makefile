# $NetBSD: Makefile,v 1.6 2010/09/14 07:33:46 obache Exp $
#

DISTNAME=	dnssd-1.4
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
