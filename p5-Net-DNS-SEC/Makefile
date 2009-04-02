# $NetBSD: Makefile,v 1.1.1.1 2009/04/02 21:59:41 pettai Exp $

DISTNAME=		Net-DNS-SEC-0.15
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}		\
			http://www.net-dns.org/download/

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://www.net-dns.org/
COMMENT=		Perl5 module for DNS SEC resolution

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Net-DNS>=0.64:../../net/p5-Net-DNS
DEPENDS+=		p5-Crypt-OpenSSL-DSA>=0.13:../../security/p5-Crypt-OpenSSL-DSA
DEPENDS+=		p5-Crypt-OpenSSL-RSA>=0.25:../../security/p5-Crypt-OpenSSL-RSA
DEPENDS+=		p5-Digest-BubbleBabble>=0.01:../../security/p5-Digest-BubbleBabble
DEPENDS+=		p5-Digest-SHA>=5.23:../../security/p5-Digest-SHA
DEPENDS+=		p5-MIME-Base32>=1.01:../../converters/p5-MIME-Base32

#PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Net-DNS-SEC
#PKG_SUPPORTED_OPTIONS=	inet6
#PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

#.if !empty(PKG_OPTIONS:Minet6)
#DEPENDS+=		p5-INET6>=2.01:../../net/p5-INET6
#DEPENDS+=		p5-Socket6-[0-9]*:../../net/p5-Socket6
#.endif

PERL5_PACKLIST=		auto/Net/DNS/SEC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
