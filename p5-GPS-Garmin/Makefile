# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	perl-GPS-0.15
PKGNAME=	p5-GPS-Garmin-0.15
CATEGORIES=	perl5 geography
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SREZIC/}
MAINTAINER=	uli@habel.name
HOMEPAGE=	http://search.cpan.org/dist/perl-GPS/
COMMENT=	GPS::Garmin access module for Perl


PERL5_PACKLIST=		auto/GPS/Garmin/.packlist

DEPENDS+= p5-Device-SerialPort>=0.12:../../comms/p5-Device-SerialPort

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
