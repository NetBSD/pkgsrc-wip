# $NetBSD: Makefile,v 1.1.1.1 2010/10/03 12:56:43 ryo-on Exp $
#

DISTNAME=	Net-UPnP-1.4.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SK/SKONNO/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/S/SK/SKONNO/
COMMENT=	Perl extension for UPnP
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Net/UPnP/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
