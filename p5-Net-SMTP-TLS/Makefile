# $NetBSD: Makefile,v 1.4 2010/04/15 07:10:07 athaba Exp $
#

DISTNAME=		Net-SMTP-TLS-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		perl5 mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		athaba@users.sourceforge.net
HOMEPAGE=		http://search.cpan.org/dist/Net-SMTP-TLS/
COMMENT=		SMTP client module supporting TLS and AUTH

DEPENDS+=		p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Net/SMTP/TLS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
