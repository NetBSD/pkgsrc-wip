# $NetBSD: Makefile,v 1.2 2008/02/14 13:41:49 athaba Exp $
#

DISTNAME=	Net-SMTP-TLS-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 mail
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AW/AWESTHOLM/

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://search.cpan.org/~awestholm/Net-SMTP-TLS-0.12/
COMMENT=	An SMTP clien module supporting TLS and AUTH

DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Net/SMTP/TLS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
